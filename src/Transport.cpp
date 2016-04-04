#include "Transport.h"

// ПО КАКИМ ПРИЧИНАМ НЕ РАБОТАЕТ РАНДОМ!?

using namespace std;

Transport::Transport(int sits) {
    while (rand_init(sits));
}

Transport::Transport() {
    while (rand_init(10));
}

int Transport::make_rand(int left, int right /*const boost::random::minstd_rand gn*/) const {
    //boost::random::uniform_int_distribution<> dist(left, right);
    //return dist(gn);

    int tmp = rand() % (right - left) + left;
    return tmp;

}

std::string Transport::where_to_go() const {
    //const boost::random::minstd_rand gen;
    int ind = make_rand(0, 15);
    return destinations[ind];
}

int Transport::rand_init(int sits) {
    //const boost::random::minstd_rand gen(time(0));
    try {
        num_sits = make_rand(5, sits);

        int minute = make_rand(0, 59);
        int hour = make_rand(0,24);
        departure_time = {hour, minute};

        transport_num = make_rand(1, 999999);

        destination = where_to_go();
    }
    catch(...) {
        cout << "incorrect creation!" << endl;
        return (1);
    }
    return 0;
}

Transport::~Transport() {
}
