#include "Plain.h"

using namespace std;

Plain::Plain() : Transport(90) {
    while(rand_init() != 0) {};
}

Plain::~Plain() {
}

int Plain::rand_init() {
    try {
        num_rows = 2 * make_rand(1,4);
        economy_class_price = make_rand(3000, 80000);
        business_class_price = make_rand(economy_class_price + 2000, 200000);
        business_class_num = static_cast<int> (num_sits * 0.2);
    }
    catch(...) {
        cout << "incorrect creation! Trying again!";
        return (1);
    }
    return 0;
}

int Plain::check_place(int row, int sit) const {

    if ((row > num_rows) || (row < 0))  {
        throw (Incorrect_input("row"));
    } //выход по некорректному полю "ряд"

    if ((sit > num_sits) || (sit < 0))  {
        throw (Incorrect_input("sit"));
    } //выход по некорректному полю "место"

    //место корректное, возвращаем как результат - цену с нужным знаком
    if (sit > business_class_num) {
        return economy_class_price;
    }
    else {
        return (- business_class_price);
    }
}

void Plain::print_info() const {
    cout.exceptions(ios_base::badbit | ios_base::failbit | ios_base::eofbit);
    cout << "Root number - " << transport_num << endl;
    cout << "Destinations - " << destination << endl;
    cout << "Departure time - " << departure_time.hours << ":" << departure_time.minutes << endl;
    cout << "Business class price - " << business_class_price << "r." << endl;
    cout << "Econommy class price - " << economy_class_price << "r." << endl;
    cout << endl;
}
