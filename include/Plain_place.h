#ifndef PLAIN__PLACE_H
#define PLAIN__PLACE_H

#include "Vectr.h"
#include <stdlib.h>
#include <iostream>
#include "Place.h"

class Plain_place : public Place
{
    public:
        Plain_place(int _row, int _sit, int _klass, int _price);
        ~Plain_place();

        void print_place_info() const;
        bool operator == (const Plain_place &right);
    protected:
    private:
        int row;
        int sit;
        int klass;
        int price;
};

#endif // PLAIN__PLACE_H
