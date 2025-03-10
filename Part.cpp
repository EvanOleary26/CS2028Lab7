#include "Part.h"

std::string Part::getPartInfo() {
    return std::to_string(sku) + " " + description;
}

bool Part::Available(int day, int month, int year) {
    //replace return with actual code
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
