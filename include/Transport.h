#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "Vectr.h"
#include <stdlib.h>
#include <iostream>
#include <ctime>

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
                                 "Beijing", "St. Petersburg", "Nizhniy Novgorod", "Yerevan",
                                 "London", "Vladivistoк", "Kiev", "Vladikavkaz",
                                 "Zagreb", "Minsk", "Oriol", "Sofia",
                                 "Rome", "Verona", "Narvik", "Kardiff"
                                };
        std::string where_to_go() const;
        int rand_init(int sits);
};

#endif // TRANSPORT_H
