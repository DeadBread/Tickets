#include "Ticket.h"
#include <iostream>

using namespace std;

Ticket::Ticket() {
}

Ticket::Ticket(std::string fname,
               std::string lname,
               unsigned long doc_num,
               char _sex,
               int t_num,
               std::string dest,
               Time time,
               shared_ptr<Place> place)
{
    first_name = fname;
    last_name = lname;
    doc_number = doc_num;
    sex = _sex;
    transport_num = t_num;
    destination = dest;
    departure_time = time;
    my_place = place;
    //ctor
}

void Ticket::print_info() {
    try {
        cout.exceptions(ios_base::badbit | ios_base::failbit | ios_base::eofbit);
        cout << "First name - " << first_name << endl;
        cout << "Last name - " << last_name << endl;
        cout << "Document number - " << doc_number << endl;
        cout << "Sex - " << sex << endl;
        cout << "Rout number - " << transport_num << endl;
        cout << "Destination - " << destination << endl;
        cout << "Departure time - " << departure_time.hours << ":" << departure_time.minutes << endl;
        my_place -> print_place_info();
    }
    catch(...) {
        cout << "Output problems!" << endl;
    }
}

Ticket::~Ticket(){
}
