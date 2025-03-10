#include "Part.h"

#include <map>

std::map<int, int> months = {
    {1, 31},
    {2, 28},
    {3, 31},
    {4, 30},
    {5, 31},
    {6, 30},
    {7, 31},
    {8, 31},
    {9, 30},
    {10, 31},
    {11, 30},
    {12, 31}
};

std::string Part::getPartInfo() {
    return std::to_string(sku) + " " + description;
}

bool Part::Available(int month, int day) {
    if (quantityOnHand > 0) {
        return true;
    }

    if (month == 1) {
        month = 12;
    } else {
        month--;
    }

    if (day > months[month]) {
        day = months[month];
    }

    if (day + leadTime > months[month]) {
        return true;
    }

    return false;
    
}

bool Part::operator>(const Part &right) const {
    return this->sku > right.sku;
}

bool Part::operator<(const Part &right) const {
    return this->sku < right.sku;
}

bool Part::operator==(const Part &right) const {
    return this->sku == right.sku;
}
