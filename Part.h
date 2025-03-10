#ifndef __PART__H
#define __PART__H

#include <iostream>


class Part {
    private:
        int sku;            //Stock Keeping Unit
        std::string description;
        int price;
        std::string uom;    //Unit of Measure
        int leadTime;
        int quantityOnHand;

    public:
        //Constutructors
        Part() : sku(0), description(""), price(0), uom(""), quantityOnHand(0), leadTime(0) {};
        Part(int sku, std::string description, int price, std::string uom, int leadTime, int quantityOnHand = 0) 
         : sku(sku), description(description), price(price), uom(uom), leadTime(leadTime), quantityOnHand(quantityOnHand) {};

        //Functions
        std::string getPartInfo();
        int getPrice() { return price; }
        bool inStock() { return quantityOnHand > 0; }
        bool Available(int month, int day);

        //Operator Overloads
        bool operator>(const Part &right) const;
        bool operator<(const Part &right) const;
        bool operator==(const Part &right) const;

};







#endif