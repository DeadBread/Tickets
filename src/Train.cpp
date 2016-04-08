#include "Train.h"
#include <iostream>

using namespace std;

Train::Train() : Transport(140) {
    while (rand_init());
}

Train::~Train() {
}

int Train::rand_init() {
    try {
        //boost::random::minstd_rand gen (std::time(0));

        num_cars = make_rand(1,25);
        first_class_price = make_rand(5000,80000);
        second_class_price = make_rand(first_class_price - 3000, first_class_price);
        first_class_number =  static_cast< int >(num_cars * 0.2); //почему бы и нет
    }
    catch(...) { //если возникают любые исключения
        cout << "incorrect creation! Try again!";
        return (1);
    }

    return 0;
}

void Train::print_info() const  {   //может кидать исключения вывода
    cout.exceptions(ios_base::badbit | ios_base::failbit | ios_base::eofbit);
    cout << "Train number - " << transport_num << endl;
    cout << "Destination - " << destination << endl;
    cout << "Departure time - " << departure_time.hours << ":" << departure_time.minutes << endl;
    cout << "First class price" << first_class_price << endl;
    cout << "Second class price" << second_class_price << endl;
}

int Train::check_place(int car, int sit) const {

    if ((car > num_cars) || (car < 1))  {
        throw (Incorrect_input("car"));
    } //выход по некорректному количеству вагонов

    if ((sit > num_sits) || (sit < 1))  {
        throw (Incorrect_input("sit"));
    } //выход по некорректному номеру места

    if (car > first_class_number) {
        return second_class_price;
    }

    else {
        return (- first_class_price);
    }
}

