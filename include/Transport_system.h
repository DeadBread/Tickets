#ifndef TRANSPORT_SYSTEM_H
#define TRANSPORT_SYSTEM_H
#include <memory>
#include <iostream>

#include "Train.h"
#include "Plain.h"
#include "Bus.h"
using namespace std;

class Transport_system
{
    public:
        //Transport_system();
        //virtual ~Transport_system();

        static Transport_system& get_transport_system() {
            static Transport_system tmp;
            return tmp;
        }

        void add_plain(Plain &&pl) { all_plains.push_back(pl); }
        void add_train(Train &&tr) { all_trains.push_back(tr); }
        void add_bus(Bus &&bs) { all_buses.push_back(bs); }

        void print_all() const;
        void print_plains() const;
        void print_trains() const;
        void print_buses() const;

        const Vectr<Train> & get_trains() const { return all_trains; }
        const Vectr<Plain> & get_plains() const { return all_plains; }
        const Vectr<Bus> & get_buses() const { return all_buses; }

    protected:
    private:

        Transport_system();

        Vectr<Train> all_trains;
        Vectr<Plain> all_plains;
        Vectr<Bus> all_buses;
};

#endif // TRANSPORT_SYSTEM_H
