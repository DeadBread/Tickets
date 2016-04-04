#ifndef PLACE_H
#define PLACE_H

#include "Vectr.h"
#include <stdlib.h>
#include <iostream>

class Place
{
    public:
        Place();
        virtual ~Place();
        virtual void print_place_info() const = 0;

    protected:
    private:
};

#endif // PLACE_H
