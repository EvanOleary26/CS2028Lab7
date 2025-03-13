
#include <iostream>
#include <string>

#include "List.h"
#include "Part.h"
#include "Exceptions.h"

Part getUserPartInfo() {
    //Create a part object with user input
    int sku;
    std::string description;
    int price;
    std::string uom;
    int quantityOnHand;
    int leadTime;

    std::cout << "Enter the part's SKU (Stock Keeping Number): ";
    std::cin >> sku;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline left in the buffer

    std::cout << "Enter the part's Description: ";
    std::getline(std::cin, description);

    std::cout << "Enter the part's Price: ";
    std::cin >> price;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline left in the buffer

    std::cout << "Enter the part's UOM (Unit of Measure): ";
    std::getline(std::cin, uom);

    std::cout << "Enter the part's Lead Time: ";
    std::cin >> leadTime;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline left in the buffer

    std::cout << "Enter the part's Quantity On Hand: ";
    std::cin >> quantityOnHand;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline left in the buffer

    return Part(sku, description, price, uom, leadTime, quantityOnHand);
}

int main() {
    //Self testing code
    /*
    List<Part> parts;
    Part part1(1, "Part 1", 10, "Each", 5, 5);
    Part part2(2, "Part 2", 20, "Each", 10, 10);
    Part part3(3, "Part 3", 30, "Each", 15, 15);
    Part part4(4, "Part 4", 40, "Each", 20, 20);

    parts.AddItem(part1);
    parts.AddItem(part2);
    parts.AddItem(part3);

    std::cout << "Part 1: " << part1.getPartInfo() << std::endl;
    std::cout << "Part 2: " << part2.getPartInfo() << std::endl;
    std::cout << "Part 3: " << part3.getPartInfo() << std::endl;

    try {
        std::cout << parts.SeeNext().getPartInfo() << std::endl;
        std::cout << parts.SeeNext().getPartInfo() << std::endl;
        std::cout << parts.SeeNext().getPartInfo() << std::endl;
        std::cout << parts.SeePrev().getPartInfo() << std::endl;
        parts.Reset();
        std::cout << parts.SeeNext().getPartInfo() << std::endl;
        std::cout << parts.SeeAt(2).getPartInfo() << std::endl;

        std::cout << parts.IsInList(part1) << std::endl;
        std::cout << parts.GetItem(part1).getPartInfo() << std::endl;

        std::cout << part3.Available(1, 1) << std::endl;

    } catch (Exception e) {
        std::cout << "Exception: " << e.errorMessage << std::endl;
    }
*/


    int opChoice = 0;
    int partTestChoice = 0;
    int listTestChoice = 0;
    List<Part> list;
    Part part;

    while (true) {
        //Get users choice of Part or List function testing
        std::cout << "\nWhat would you like to do?" << std::endl;
        std::cout << "1. Test Part functions\n2. Test Linked List Functions\n3. Quit" << std::endl;

        opChoice = 0;
        std::cin >> opChoice;

        if (opChoice == 1) {
            //Part function testing
            while (true) {
                std::cout << "\nWhich Part function would you like to test?" << std::endl;
                std::cout << "1. getPartInfo\n2. inStock\n3. Available\n4. Display Part Info\n5. Go Back" << std::endl;

                partTestChoice = 0;
                std::cin >> partTestChoice;
                try {
                    part = *(new Part(1, "Part 1", 10, "Pound", 40));
                    if (partTestChoice == 1) {
                        //Test getPartInfo function
                        std::cout << part.getPartInfo() << std::endl;
                    }
                    else if (partTestChoice == 2) {
                        //Test inStock function
                        if (part.inStock()) {
                            std::cout << "Part is in stock" << std::endl;
                        }
                        else {
                            std::cout << "Part is not in stock" << std::endl;
                        }
                    }
                    else if (partTestChoice == 3) {
                        //Test Available function
                        std::cout << "Please enter the month, day, and year you would like to check for availability" << std::endl;
                        int month{};
                        int day{};
                        int year{};

                        std::cout << "Month (number, Jan = 1 and Dec = 12): ";
                        std::cin >> month;
                        std::cout << "Day: ";
                        std::cin >> day;
                        std::cout << "Year: ";
                        std::cin >> year;

                        if (part.Available(month, day, year)) {
                            std::cout << part.getPartInfo() << " is available" << std::endl;
                        }
                        else {
                            std::cout << part.getPartInfo() << " is not available" << std::endl;
                        }
                    }
					else if (partTestChoice == 4) {
						//Display part
                        part.display();
					}
                    else if (partTestChoice == 5) {
                        //Go back
                        break;
                    }
                    else {
                        std::cout << "Invalid choice" << std::endl;
                    }
                }
                catch (Exception e) {
                    std::cout << "Exception in Part: " << e.errorMessage << std::endl;
                }
            }
        }
        else if (opChoice == 2) {
            //List function testing
            while (true) {
                std::cout << "\nWhich List function would you like to test?" << std::endl;
                std::cout << "1. AddItem\n2. GetItem\n3. IsInList\n4. IsEmpty\n5. Size\n6. SeeNext\n7. SeePrev\n8. SeeAt\n9. Reset\n10. Display List\n11.Go Back" << std::endl;

                listTestChoice = 0;
                std::cin >> listTestChoice;

                //Ask for user part information?
                try {
                    if (listTestChoice == 1) {
                        //Test AddItem function
                        part = getUserPartInfo();
                        list.AddItem(part);
                        std::cout << "Added " << part.getPartInfo() << std::endl;
                    }
                    else if (listTestChoice == 2) {
                        //Test GetItem function
                        std::cout << "What part would you like to remove?" << std::endl;
                        part = getUserPartInfo();
                        std::cout << "Removed " << list.GetItem(part).getPartInfo() << std::endl;
                    }
                    else if (listTestChoice == 3) {
                        //Test IsInList function
                        std::cout << "Enter the part you would like to check for in the list" << std::endl;
                        part = getUserPartInfo();
                        bool inList = list.IsInList(part);
                        if (inList) {
                            std::cout << part.getPartInfo() << " is in the list" << std::endl;
                        }
                        else {
                            std::cout << part.getPartInfo() <<  " is not in the list" << std::endl;
                        }
                    }
                    else if (listTestChoice == 4) {
                        //Test IsEmpty function
						bool listempty = list.IsEmpty();
                        if (listempty) {
                            std::cout << "The list is empty" << std::endl;
                        }
                        else {
                            std::cout << "The list is not empty" << std::endl;
                        }
                    }
                    else if (listTestChoice == 5) {
                        //Test Size function
                        std::cout << "The size of the list is " << list.Size() << std::endl;
                    }
                    else if (listTestChoice == 6) {
                        //Test SeeNext function
                        std::cout << "The next part in the list is " << list.SeeNext().getPartInfo() << std::endl;
                    }
                    else if (listTestChoice == 7) {
                        //Test SeePrev function
                        std::cout << "The previous part in the list is " << list.SeePrev().getPartInfo() << std::endl;
                    }
                    else if (listTestChoice == 8) {
                        //Test SeeAt function
                        std::cout << "Where in the list would you like to look?" << std::endl;
                        int seeAtIndex = 0;
                        std::cin >> seeAtIndex;
                        std::cout << "The Part at index " << seeAtIndex << " is " << list.SeeAt(seeAtIndex).getPartInfo() << std::endl;
                    }
                    else if (listTestChoice == 9) {
                        //Test Reset function
                        list.Reset();
                        std::cout << "Reset curLocation" << std::endl;
                    }
					else if (listTestChoice == 10) {
						//Display List
						list.DisplayList();
					}
                    else if (listTestChoice == 11) {
                        //Go back
                        break;
                    }
                    else {
                        std::cout << "Invalid choice" << std::endl;
                    }
                }
                catch (Exception e) {
                    std::cout << "Exception in List: " << e.errorMessage << std::endl;
                }
            }
        }
        else if (opChoice == 3) {
            //Quit
            break;
        }
        else {
            std::cout << "Invalid choice" << std::endl;
        }
    }
    return 0;
}
