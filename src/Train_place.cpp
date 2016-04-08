#include "Train_place.h"
#include <iostream>

using namespace std;

Train_place::Train_place(int _car, int _sit, int _klass, int _price) {
    car = _car;
    sit = _sit;
    klass = _klass;
    price = _price;
    //ctor
}

void Train_place::print_place_info() const {
    cout.exceptions(ios_base::badbit | ios_base::failbit | ios_base::eofbit);
    cout << "Car - " << car << endl;
    cout << "Place - " << sit << endl;
    cout << "Class - " << klass << endl;
    cout << "Price - " << price << "р." << endl;
}

Train_place::~Train_place() {
}

bool Train_place::operator == (const Train_place &right) {
    return ((car == right.car) && (sit == right.sit));
}
