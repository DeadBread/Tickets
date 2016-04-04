#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "Vectr.h"
#include <stdlib.h>
#include <iostream>
#include <ctime>
//#include <boost/random/mersenne_twister.hpp>
//#include <boost/random/uniform_int_distribution.hpp>
//#include <boost/random/linear_congruential.hpp>

//const boost::random::minstd_rand gen(std::time(0));

class Transport
{
    public:
        Transport(int sits);
        Transport();

        virtual ~Transport();

        int get_num() const {return transport_num;}

        int get_num_sits() const {return num_sits;}

        Time get_time() const {return departure_time;}

        std::string get_destination() const {return destination;}

        virtual void print_info() const = 0;  //еще не знаю, нужно ли делать virtual

        //static const boost::random::minstd_rand gen;

    protected:
        int transport_num;
        std::string destination;
        Time departure_time;
        int num_sits;

        int make_rand(int left, int right /*const boost::random::minstd_rand gn*/) const;
    private:
        const std::string destinations[16] = {
                                 "Пекин", "Санкт-Перербург", "Нижний Новгрод", "Ереван",
                                 "Лондон", "Владивосток", "Киев", "Владикавказ",
                                 "Загреб", "Минск", "Орел", "София",
                                 "Рим", "Верона", "Нарвик", "Кардифф"
                                };
        std::string where_to_go() const;
        int rand_init(int sits);
};

#endif // TRANSPORT_H
