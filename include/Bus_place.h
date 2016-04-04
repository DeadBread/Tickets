#ifndef BUS_PLACE_H
#define BUS_PLACE_H

#include "Vectr.h"
#include <stdlib.h>
#include <iostream>

#include "Place.h"



class Bus_place : public Place
{
    public:
        Bus_place(int _sit, int _price);
        ~Bus_place();

        void print_place_info() const;
        bool operator == (const Bus_place &right);
    protected:
    private:
        int sit;
        int price;
};

#endif // BUS_PLACE_H
