#ifndef TICKETS_VECT_H
#define TICKETS_VECT_H

#include "Vectr.h"
#include "Ticket.h"
#include <iostream>
//#include <boost/make_shared.hpp>

class Tickets_vect
{
    public:
        Tickets_vect();

        int get_size () const { return all.size(); }

        void add(std::shared_ptr<Ticket> one) { all.push_back(one); }
        int find(int num_trans, unsigned long num_doc);   //поиск по номеру паспорта
        const Ticket & get(int which) {return *(all[which]);}    //исключение генерируется автоматически

    protected:
        Vectr<std::shared_ptr<Ticket>> all;  //для реализации механизма виртуальных функций.
    private:
};

#endif // TICKETS_VECT_H
