#ifndef PLAIN_H
#define PLAIN_H

#include "Transport.h"
#include "Incorrect_input.h"

#include <stdlib.h>
#include <iostream>

class Plain : public Transport
{
    public:
        Plain();

        virtual ~Plain();

        int check_place(int row, int sit) const;

        int get_num_rows() const {
            return num_rows;
        }

        virtual void print_info() const;
    protected:
    private:
        int num_rows;
        int business_class_price;
        int economy_class_price;
        int business_class_num;

        int rand_init();
};

#endif // PLAIN_H
