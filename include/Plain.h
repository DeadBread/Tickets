#ifndef PLAIN_H
#define PLAIN_H

#include "Transport.h"
#include "Incorrect_input.h"

#include <stdlib.h>
#include <iostream>

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
//хороший, годный класс! Использовать, как образец!
//видимо, надо таки делать общий предок - класс "транспорт"

class Plain : public Transport
{
    public:
        Plain();
        //Plain(int numrows, int numsits, int plainnum, int businessclassprice, int economyclassprice);
        //Plain(char r);  //что-то из этого явно лишнее
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
        // Plain& great_init();
};

#endif // PLAIN_H
