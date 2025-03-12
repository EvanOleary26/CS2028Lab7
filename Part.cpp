#include "Part.h"
#include "Exceptions.h"
#include <string>
#include <ctime>
#include <map>

std::map<int, int> months = {
    //A dictionary with all the months and their corresponding number of days
    {1, 31},    //January
    {2, 28},    //February
    {3, 31},    //March
    {4, 30},    //April
    {5, 31},    //May
    {6, 30},    //June
    {7, 31},    //July
    {8, 31},    //August
    {9, 30},    //September
    {10, 31},   //October
    {11, 30},   //November
    {12, 31}    //December
};

std::string Part::getPartInfo() {
    return description + " : " + std::to_string(sku);
}

bool Part::Available(int inMonth, int inDay, int inYear) {
    //If the quantity on hand is greater than 0, the part is available
    if (quantityOnHand > 0) {
        return true;
    }

    if (inMonth < 1 || inMonth > 12) {
        throw Exception(1, "Invalid month");
    }

    if (inDay < 1 || inDay > months[inMonth]) {
        throw Exception(1, "Invalid day");
    }

    //Get current date
    time_t now = time(0);
    struct tm *ltm = localtime(&now);

    int currentMonth = ltm->tm_mon + 1;
    int currentDay = ltm->tm_mday;
    int currentYear = ltm->tm_year + 1900;
    
    if (inYear < currentYear) {
        //If the year requested is less than the current year, the part is not available
        return false;
    }

    if (inYear > currentYear) {
        inMonth += 12;
    }
    if (inYear == currentYear) {
        //Check if the lead time added to the current date is less than the date requested
        if (currentMonth == inMonth) {
            if (currentDay + leadTime <= inDay) {
                //If the current month is the same as the requested month, 
                //and the current day plus the lead time is less than the requested day, the part is available
                return true;
            }
        } else if (currentMonth < inMonth) {
            if ( (currentDay + leadTime) % months[currentMonth] >= inDay) {
                return true;
            }
        }
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
