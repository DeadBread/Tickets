#include "Bus.h"

using namespace std;

Bus::Bus() : Transport(80) {
    while (rand_init());
}

Bus::~Bus() {
}

int Bus::rand_init() {
    //boost::random::minstd_rand gen (std::time(0));
    try {
        price = make_rand(200, 4000);
    }
    catch(...)  {
        cout << "incorrect creation! Trying again!";
        return (1);
    }

    return 0;
}

void Bus::print_info() const {   //может кидать исключения вывода
    cout.exceptions(ios_base::badbit | ios_base::failbit | ios_base::eofbit);
    cout << "Root number" << transport_num << endl;
    cout << "Destination - " << destination << endl;
    cout << "Departure time- " << departure_time.hours << ":" << departure_time.minutes << endl;
    cout << "Ticket price" << price << endl;
}

int Bus::check_place(int sit) const { //кидает "неверный ввод"
    if ((sit > num_sits) || (sit < 1))  {throw (Incorrect_input());}
    else {return price;}
}
