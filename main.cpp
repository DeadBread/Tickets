#include "main.h"

using namespace std;

int main() {
    cin.exceptions(ios_base::badbit | ios_base::failbit | ios_base::eofbit);    //учит cin кидать исключения

    srand(std::time(0));
    int i = interface();
    return 0;
}

//ИНТЕРФЕЙС. ВОЗМОЖНО, СТОИТ ВЫНЕСТИ В ОТДЕЛЬНЫЙ БИНАРНИК

int interface() {
    cout << "Welcome to the system! Do you want to start?" << endl;

    int tr = yes_or_no();
    if (tr) {
        return 0;
    }

    Transport_system ts;
    Tickets_vect tickets;

    try {
        creation (ts, tickets);
    }
    catch(Wrong_number&) {
        cout << '\n' << "Incorrect number!" << '\n' << endl;
        interface();
        return 0;
    }  //  ОПАСНО! ЧТО БУДЕТ С ПАМЯТЬЮ?
    catch(ios_base::failure) {
        cout << '\n' << "Input failure!" << '\n' << endl;
        cin.clear();
        interface();
        return 0;
    }

    int l = 1;
    while (l) {
        try {
            cout << "Do you want to buy a ticket?" << endl;
            tr = yes_or_no();
            if (tr) {
                cout << "Do you want to find the info about your ticket?" << endl;
                tr = yes_or_no();
                if (tr) {
                    cout <<"I can't help you then :(" << endl;
                    return 0;
                }

                //иначе - переходим в функцию поиска
                finder(tickets);
                continue;
            }

            cout << "Choose transport: t for train, p for plain and b for bus" << endl;
            char trans;
            cin >> trans;

            int check = buy(ts, tickets, trans);
            if (check) {
                cout << '\n' << "invalid choice!" << '\n' << endl;
            }
         }
         catch(...) {
            cout << '\n' << "Very incorrect input!" << '\n' << endl;
         }
    }
    return 0;
}

int creation (Transport_system &ts, Tickets_vect &tickets) //насколько я понимаю, ТС в функции изменится
{
    cout << "enter number of plains" << endl;
    int pl_num;
    cin >> pl_num;
    if ((pl_num < 0)) {
        throw (Wrong_number());
    }

    cout << "enter number of trains" << endl;
    int tr_num;
    cin >> tr_num;
    if ((tr_num < 0)) {
        throw (Wrong_number());
    }

    cout << "enter number of buses" << endl;
    int bs_num;
    cin >> bs_num;
    if ((bs_num < 0)) {
        throw (Wrong_number());
    }

    int i;

    for (i = 0; i < pl_num; i++) {
        ts.add_plain(Plain());   //временный, рандомный объект. тут же удалится
    }
    for (i = 0; i < tr_num; i++) {
        ts.add_train(Train());
    }
    for (i = 0; i < bs_num; i++) {
        ts.add_bus(Bus());
    }

    cout << "creation complete!" << endl;

    return 0;
}

int yes_or_no() {
    char inch = '0';
    while ((inch != 'y') && (inch != 'n')) {
        cin >> inch;
    }

    if (inch == 'n') {
        return 1;
    }
    return 0;
}

int buy(const Transport_system &st, Tickets_vect &tickets, char trans_type) {

    cin.exceptions(ios_base::badbit | ios_base::failbit | ios_base::eofbit);

    if ((trans_type != 't') && (trans_type != 'p') && (trans_type != 'b')) {
        throw(Incorrect_input("transport type"));
    }

    while (1) {
        try {
            string name;
            string lastname;
            int doc_num;
            char sex;
            cout << "enter your name" << endl;
            cin >> name;
            cout << "enter your last name" << endl;
            cin >> lastname;
            cout << "enter your document number" << endl;
            cin >> doc_num;
            cout << "enter your sex" << endl;
            cin >> sex;
            switch (trans_type) {
            case 'p': {
                cout <<"what plain do you need?" << endl;
                st.print_plains();
                int num;
                cin >> num;

                int ind = -1;

                const Vectr<Plain> &plains = st.get_plains();

                for (int i = 0; i < plains.size(); i++) {
                    if (plains[i].get_num() == num) {
                        ind = i;
                        break;
                    }
                }
                if (ind < 0) {
                    throw (Incorrect_input());
                }

                int row;
                int sit;
                int klass;
                cout <<"choose the row from 1 to " << plains[ind].get_num_rows() << endl;
                cin >> row;
                cout <<"choose the place from 1 to " << plains[ind].get_num_sits() << endl;
                cin >> sit;

                int prc = plains[ind].check_place(row, sit);
                //if (prc == 0) {throw ("incorrect place");}
                if (prc > 0) {
                    klass = 2;
                }
                else {
                    klass = 1;
                    prc = -prc;
                }

                shared_ptr<Place> my_place = make_shared <Plain_place> (row, sit, klass, prc);

                string dest = plains[ind].get_destination();
                Time time = plains[ind].get_time();

                shared_ptr<Ticket> tmp = make_shared <Ticket> (name,
                                                     lastname,
                                                     doc_num,
                                                     sex,
                                                     num,
                                                     dest,
                                                     time,
                                                     my_place);

                tickets.add(tmp);

                cout << "вы успешно приобрели билет" << endl;
                cout << '\n';
                tmp->print_info();

                break;
            }

            case 't': {
                cout <<"what train do you need?" << endl;
                st.print_trains();

                int num;
                cin >> num;

                int ind = -1;

                const Vectr<Train> &trains = st.get_trains();

                for (int i = 0; i < trains.size(); i++) {
                    if (trains[i].get_num() == num) {
                        ind = i;
                        break;
                    }
                }

                if (ind < 0) {
                    throw (Incorrect_input());
                }

                int car;
                int sit;
                int klass;
                cout <<"choose the car from 1 to " << trains[ind].get_num_cars() << endl;
                cin >> car;
                cout <<"choose the place from 1 to " << trains[ind].get_num_sits() << endl;
                cin >> sit;

                int prc = trains[ind].check_place(car, sit);
                 //if (prc == 0) {throw ("incorrect place");}
                if (prc > 0) {
                    klass = 2;
                }

                else {
                    klass = 1;
                    prc = -prc;
                }

                shared_ptr<Place> my_place = make_shared<Train_place> (car, sit, klass, prc);

                string dest = trains[ind].get_destination();
                Time time = trains[ind].get_time();


                shared_ptr<Ticket> tmp = make_shared<Ticket>(name,
                                                 lastname,
                                                 doc_num,
                                                 sex,
                                                 num,
                                                 dest,
                                                 time,
                                                 my_place);
                tickets.add(tmp);

                cout << "вы успешно приобрели билет" << endl;
                cout << '\n';
                tmp->print_info();

                break;
            }

            case 'b': {
                cout <<"what bus do you need?" << endl;
                st.print_buses();

                int num;
                cin >> num;

                int ind = -1;

                const Vectr<Bus> &buses = st.get_buses();

                for (int i = 0; i < buses.size(); i++) {
                    if (buses[i].get_num() == num) {
                        ind = i;
                        break;
                    }
                }
                if (ind < 0) {
                    throw (Incorrect_input());
                }

                int sit;
                cout <<"choose the place from 1 to " << buses[ind].get_num_sits() << endl;
                cin >> sit;

                int prc = buses[ind].check_place(sit);
                 //if (prc == 0) {throw ("incorrect place");}

                shared_ptr<Place> my_place = make_shared<Bus_place> (sit, prc);

                string dest = buses[ind].get_destination();
                Time time = buses[ind].get_time();

                shared_ptr<Ticket> tmp = make_shared<Ticket> (name,
                                                             lastname,
                                                             doc_num,
                                                             sex,
                                                             num,
                                                             dest,
                                                             time,
                                                             my_place);
                tickets.add(tmp);

                cout << "вы успешно приобрели билет" << endl;
                cout << '\n';
                tmp->print_info();

                break;
             }

            }


            return 0;

        }
        catch(Incorrect_input &tmp) {
            cout << "Incorrect input of " << tmp.get_msg() << endl;
            cin.clear();
            cin.ignore(100, '\n');
            //будет прописано
        }
        catch(Wrong_number&) {
            cout << "Wrong number!" << endl;
        }
        catch(ios_base::failure) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "fail at input!" << '\n' << endl;
        }
        catch(...) {
            cout << "unknown exception!" << endl;
        }
    }

    return 0;
}

void finder(Tickets_vect &tickets) {
    int trans_num;
    int doc_num;
    cout << "Welcome to finder!" << '\n' << "Enter the transport number!" << endl;
    cin >> trans_num;
    cout << "Enter the document number!" << endl;
    cin >> doc_num;

    int pos = tickets.find(trans_num, doc_num);
    if (pos < 0) {
        cout << "Found nothing" << endl;
    }
    else {
        Ticket tmp = tickets.get(pos);
        cout <<"Found ticket" << endl;
        tmp.print_info();
    }
}



