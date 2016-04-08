#ifndef BUS_H
#define BUS_H

#include "Transport.h"

#include <stdlib.h>
#include <iostream>
#include "Vectr.h"
#include "Incorrect_input.h"

class Bus : public Transport
{
    public:
        Bus();
        virtual ~Bus();

        virtual void print_info() const;
        int check_place (int sit) const;
    protected:
    private:
        int price;
        int rand_init();
};

#endif // BUS_H
