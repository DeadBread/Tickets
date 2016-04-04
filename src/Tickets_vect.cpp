#include "Tickets_vect.h"
#include <iostream>

Tickets_vect::Tickets_vect() {
}

int Tickets_vect::find(int num_trans, unsigned long num_doc) {
    std::cout << all.size() << std::endl;
    for (int i = 0; i < all.size(); i++) {
        if (((all[i])->get_doc_number() == num_doc) && ((all[i])->get_transport_num() == num_trans)) {
            return i;
        }
    }

    return -1;
}
