#include <iostream>
#include <string>

#include "List.h"
#include "Part.h"
#include "Exceptions.h"

Part getUserPartInfo() {
    // Create a part object with user input
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
    int choice = 0;
    List<Part> list;
    Part part;

    while (true) {
        // Unified menu for both Part and List functions
        std::cout << "\nWhat would you like to do?" << std::endl;
        std::cout << "1. AddItem to List\n2. GetItem from List\n3. Check if Part is in List\n4. Check if List is Empty\n";
        std::cout << "5. Get List Size\n6. See Next Part in List\n7. See Previous Part in List\n8. See Part at Index\n";
        std::cout << "9. Reset List\n10. Display List\n";

        // Part options section
        std::cout << "\n--- Part Options (Require the list to not be empty) ---" << std::endl;
        std::cout << "11. Test getPartInfo\n12. Test inStock\n13. Test Available\n14. Display Part Info\n";

        // Quit option
        std::cout << "15. Quit" << std::endl;

        std::cin >> choice;

        try {
            if (choice == 1) {
                // AddItem to List
                part = getUserPartInfo();
                list.AddItem(part);
                std::cout << "Added " << part.getPartInfo() << " to the list" << std::endl;
            } else if (choice == 2) {
                // GetItem from List
                std::cout << "Enter the part you would like to remove:" << std::endl;
                part = getUserPartInfo();
                std::cout << "Removed " << list.GetItem(part).getPartInfo() << " from the list" << std::endl;
                part = *(new Part());
            } else if (choice == 3) {
                // Check if Part is in List
                std::cout << "Enter the part you would like to check for in the list:" << std::endl;
                part = getUserPartInfo();
                if (list.IsInList(part)) {
                    std::cout << part.getPartInfo() << " is in the list" << std::endl;
                } else {
                    std::cout << part.getPartInfo() << " is not in the list" << std::endl;
                }
            } else if (choice == 4) {
                // Check if List is Empty
                if (list.IsEmpty()) {
                    std::cout << "The list is empty" << std::endl;
                } else {
                    std::cout << "The list is not empty" << std::endl;
                }
            } else if (choice == 5) {
                // Get List Size
                std::cout << "The size of the list is " << list.Size() << std::endl;
            } else if (choice == 6) {
                // See Next Part in List
                part = list.SeeNext();
                std::cout << "The next part in the list is " << part.getPartInfo() << std::endl;
            } else if (choice == 7) {
                // See Previous Part in List
                part = list.SeePrev();
                std::cout << "The previous part in the list is " << part.getPartInfo() << std::endl;
            } else if (choice == 8) {
                // See Part at Index
                int index = 0;
                std::cout << "Enter the index of the part you want to see: ";
                std::cin >> index;
                part = list.SeeAt(index);
                std::cout << "The part at index " << index << " is " << part.getPartInfo() << std::endl;
            } else if (choice == 9) {
                // Reset List
                list.Reset();
                std::cout << "Reset curLocation" << std::endl;
            } else if (choice == 10) {
                // Display List
                list.DisplayList();
            } else if (choice >= 11 && choice <= 14) {
                // Check if the list is empty before allowing Part functions
                if (list.IsEmpty()) {
                    std::cout << "The list is empty. Please add items to the list before testing Part functions." << std::endl;
                    continue;
                }

                if (choice == 11) {
                    // Test getPartInfo function
                    std::cout << part.getPartInfo() << std::endl;
                } else if (choice == 12) {
                    // Test inStock function
                    if (part.inStock()) {
                        std::cout << "Part is in stock" << std::endl;
                    } else {
                        std::cout << "Part is not in stock" << std::endl;
                    }
                } else if (choice == 13) {
                    // Test Available function
                    std::cout << "Please enter the month, day, and year you would like to check for availability" << std::endl;
                    int month{}, day{}, year{};
                    std::cout << "Month (number, Jan = 1 and Dec = 12): ";
                    std::cin >> month;
                    std::cout << "Day: ";
                    std::cin >> day;
                    std::cout << "Year: ";
                    std::cin >> year;

                    if (part.Available(month, day, year)) {
                        std::cout << part.getPartInfo() << " is available" << std::endl;
                    } else {
                        std::cout << part.getPartInfo() << " is not available" << std::endl;
                    }
                } else if (choice == 14) {
                    // Display part
                    part.display();
                }
            } else if (choice == 15) {
                // Quit
                break;
            } else {
                std::cout << "Invalid choice" << std::endl;
            }
        } catch (Exception e) {
            std::cout << "Exception: " << e.errorMessage << std::endl;
        }
    }

    return 0;
}