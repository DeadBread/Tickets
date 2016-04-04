#ifndef INCORRECT_INPUT_H
#define INCORRECT_INPUT_H

#include <exception>
#include <string>

class Incorrect_input : public std::exception
{
    public:
        Incorrect_input();
        Incorrect_input(std::string &&tmp);

        virtual ~Incorrect_input();
        std::string get_msg() const {
            return msg;
        }
    protected:
    private:
        std::string msg;
};

#endif // INCORRECT_INPUT_H
