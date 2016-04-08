#ifndef VECTR_H
#define VECTR_H

#include <vector>

template <typename T>
class Vectr : public std::vector <T>
{
    public:
        Vectr() : std::vector<T>() {};
        Vectr(int s) : std::vector<T>(s) {}

        T& operator[] (int i)
        {
            return this->at(i);
        }
        const T& operator[] (int i) const
        {
            return this->at(i);
        }
    protected:
    private:
};

//объявим здесь же структуру "время" для указания времени отправления

struct Time
{
    int hours;
    int minutes;
};

#endif // VECTR_H
