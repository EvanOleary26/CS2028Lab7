#include <iostream>

#include "List.h"
#include "Part.h"
#include "Exceptions.h"

Part getUserPartInfo() {
    int sku;
    std::string description;
    int price;
    std::string uom;
    int quantityOnHand;
    int leadTime;

    std::cout << "Enter the part's SKU (Stock Keeping Number): ";
    std::cin >> sku;
    std::cout << "Enter the part's Description: ";
    std::cin >> description;
    std::cout << "Enter the part's Price: ";
    std::cin >> price;
    std::cout << "Enter the part's UOM (Unit of Measure): ";
    std::cin >> uom;
    std::cout << "Enter the part's Lead Time: ";
    std::cin >> leadTime;
    std::cout << "Enter the part's Quantity On Hand: ";
    std::cin >> quantityOnHand;
    
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
    while (true) {
        //Get users choice of Part or List function testing
        std::cout << "\nWhat would you like to do?" << std::endl;
		std::cout << "1. Test Part functions\n2. Test Linked List Functions\n3. Quit" << std::endl;
		
		opChoice = 0;
		std::cin >> opChoice;

        if (opChoice == 1){
            //Part function testing
            while (true) {
                std::cout << "\nWhich Part function would you like to test?" << std::endl;
                std::cout << "1. getPartInfo\n3. inStock\n4. Available\n5. Go Back" << std::endl;
                
                partTestChoice = 0;
                std::cin >> partTestChoice;


                if (partTestChoice == 1) {
                    //Test getPartInfo function
                    std::cout << part1.getPartInfo() << std::endl;
                } else if (partTestChoice == 2) {
                    //Test inStock function
                    std::cout << part1.inStock() << std::endl;
                } else if (partTestChoice == 3) {
                    //Test Available function
                    std::cout << part1.Available(1, 1) << std::endl;
                } else if (partTestChoice == 4) {
                    //Go back
                    break;
                } else {
                    std::cout << "Invalid choice" << std::endl;
                }
            }
        } else if (opChoice == 2) {
            //List function testing
            while (true) {
                std::cout << "\nWhich List function would you like to test?" << std::endl;
                std::cout << "1. AddItem\n2. GetItem\n3. IsInList\n4. IsEmpty\n5. Size\n6. SeeNext\n7. SeePrev\n8. SeeAt\n9. Reset\n10. Go Back" << std::endl;
                
                listTestChoice = 0;
                std::cin >> listTestChoice;

                //Ask for user part information

                if (listTestChoice == 1) {
                    //Test AddItem function
                    parts.AddItem(getUserPartInfo());
                    std::cout << "Added Part 4" << std::endl;
                } else if (listTestChoice == 2) {
                    //Test GetItem function
                    std::cout << parts.GetItem(part4).getPartInfo() << std::endl;
                } else if (listTestChoice == 3) {
                    //Test IsInList function
                    std::cout << parts.IsInList(part4) << std::endl;
                } else if (listTestChoice == 4) {
                    //Test IsEmpty function
                    std::cout << parts.IsEmpty() << std::endl;
                } else if (listTestChoice == 5) {
                    //Test Size function
                    std::cout << parts.Size() << std::endl;
                } else if (listTestChoice == 6) {
                    //Test SeeNext function
                    std::cout << parts.SeeNext().getPartInfo() << std::endl;
                } else if (listTestChoice == 7) {
                    //Test SeePrev function
                    std::cout << parts.SeePrev().getPartInfo() << std::endl;
                } else if (listTestChoice == 8) {
                    //Test SeeAt function
                    std::cout << parts.SeeAt(2).getPartInfo() << std::endl;
                } else if (listTestChoice == 9) {
                    //Test Reset function
                    parts.Reset();
                    std::cout << "Reset curLocation" << std::endl;
                } else if (listTestChoice == 10) {
                    //Go back
                    break;
                }else {
                    std::cout << "Invalid choice" << std::endl;
                }
            }
        } else if (opChoice == 3) {
            break;
        } else {
            std::cout << "Invalid choice" << std::endl;
        }

    }
    return 0;
}