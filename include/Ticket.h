#ifndef TICKET_H
#define TICKET_H

#include <memory>
#include <string>
#include "Vectr.h"
//#include <boost/shared_ptr.hpp>
#include "Place.h"

class Ticket
{
    public:
        Ticket();
        Ticket(std::string fname,
               std::string lname,
               unsigned long doc_num,
               char sex,
               int t_num,
               std::string dest,
               Time time,
               std::shared_ptr<Place> place);

        virtual ~Ticket();

        unsigned long get_doc_number() const {return doc_number;}
        int get_transport_num() const {return transport_num;}

        void print_info();
    protected:
    private:
        std::string first_name;
        std::string last_name;
        unsigned long doc_number;
        char sex;

        int transport_num;
        std::string destination;
        Time departure_time;

        std::shared_ptr<Place> my_place = nullptr;
};

#endif // TICKET_H
