#ifndef TRAIN_PLACE_H
#define TRAIN_PLACE_H

#include "Vectr.h"
#include <stdlib.h>
#include <iostream>
#include <Place.h>


class Train_place : public Place
{
    public:
        Train_place(int _car, int _sit, int _klass, int _price);
        ~Train_place();

        void print_place_info() const;
        bool operator == (const Train_place &right);
    protected:
    private:
        int car;
        int sit;
        int klass;
        int price;
};

#endif // TRAIN_PLACE_H
