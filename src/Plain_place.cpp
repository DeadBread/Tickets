#include "Plain_place.h"

using namespace std;

Plain_place::Plain_place(int _row, int _sit, int _klass, int _price) {
    row = _row;
    sit = _sit;
    klass = _klass;
    price = _price;
}

void Plain_place::print_place_info() const {
    cout.exceptions(ios_base::badbit | ios_base::failbit | ios_base::eofbit);
    cout << "Row - " << row << endl;
    cout << "Sit - " << sit << endl;
    cout << "Class - " << klass << endl;
    cout << "Price - " << price << "р." << endl;
}

Plain_place::~Plain_place() {
}

bool Plain_place::operator==(const Plain_place &right) {
    return ((row == right.row) && (sit == right.sit));
}
