#include <iostream>

#include "List.h"
#include "Part.h"



int main() {

    List<Part> parts;
    Part part1(1, "Part 1", 10, "Each", 5, 5);
    Part part2(2, "Part 2", 20, "Each", 10, 10);
    Part part3(3, "Part 3", 30, "Each", 15, 15);
    
    parts.AddItem(&part1);
    parts.AddItem(&part2);
    parts.AddItem(&part3);

    std::cout << "Part 1: " << part1.getPartInfo() << std::endl;
    std::cout << "Part 2: " << part2.getPartInfo() << std::endl;
    std::cout << "Part 3: " << part3.getPartInfo() << std::endl;




    return 0;
}