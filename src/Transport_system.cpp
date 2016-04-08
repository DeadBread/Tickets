#include "Transport_system.h"

using namespace std;

Transport_system::Transport_system() {}

void Transport_system::print_plains() const {
    auto iter = all_plains.begin();
    decltype (iter) fin = all_plains.end();
    while (iter != fin) {
        (*iter).print_info();
        cout << '\n';
        iter++;
    }
}

void Transport_system::print_trains() const {
    auto iter = all_trains.begin();
    decltype (iter) fin = all_trains.end();
    while (iter != fin) {
        (*iter).print_info();
        cout << '\n';
        iter++;
    }
}

void Transport_system::print_buses() const {
    auto iter = all_buses.begin();
    decltype (iter) fin = all_buses .end();
    while (iter != fin) {
        (*iter).print_info();
        cout << '\n';
        iter++;
    }
}

