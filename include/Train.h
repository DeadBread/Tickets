#ifndef TRAIN_H
#define TRAIN_H

#include "Transport.h"
#include "Incorrect_input.h"

#include "Vectr.h"
#include <stdlib.h>
#include <iostream>

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

class Train : public Transport
{
    public:
        Train();
        virtual ~Train();

        virtual void print_info() const;

        int get_num_cars() const {
            return num_cars;
        }

        int check_place(int car, int sit) const;   //по замыслу - возвращает цену билета (если 1 класс - со знаком минус)
    protected:
    private:
        int num_cars;
        int first_class_price;
        int second_class_price;
        int first_class_number;
        int rand_init();
};

#endif // TRAIN_H
