#ifndef __PART__H
#define __PART__H

#include <iostream>


class Part {
    private:
        int sku;            //Stock Keeping Unit
        std::string description;
        int price;
        std::string uom;    //Unit of Measure
        int quantityOnHand;
        int leadTime;

    public:
        //Constutructors
        Part() : sku(0), description(""), price(0), uom(""), quantityOnHand(0), leadTime(0) {};
        Part(int sku, std::string description, int price, std::string uom, int quantityOnHand = 0, int leadTime) 
         : sku(sku), description(description), price(price), uom(uom), quantityOnHand(quantityOnHand), leadTime(leadTime) {};

        //Functions
        std::string getPartInfo();
        int getPrice() { return price; }
        bool inStock() { return quantityOnHand > 0; }
        bool Available(int date);

        //Operator Overloads
        bool operator>(const Part &right) const;
        bool operator<(const Part &right) const;
        bool operator==(const Part &right) const;

};







#endif