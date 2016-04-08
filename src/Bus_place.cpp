#include "Bus_place.h"

using namespace std;

Bus_place::Bus_place(int _sit, int _price) {
    sit = _sit;
    price = _price;
}

void Bus_place::print_place_info() const {
    cout.exceptions(ios_base::badbit | ios_base::failbit | ios_base::eofbit);
    cout << "Sit - " << sit << endl;
    cout << "Price - " << price << "р." << endl;
}

Bus_place::~Bus_place() {
}

bool Bus_place::operator == (const Bus_place &right) {
    return (sit == right.sit);
}
