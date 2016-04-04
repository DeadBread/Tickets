#ifndef PLAIN__PLACE_H
#define PLAIN__PLACE_H


class Plain__place
{
    public:
        Plain__place();
        virtual ~Plain__place();

        Plain* my_plain;

        virtual void set_place();
        virtual void print_place_info();
    protected:
    private:
        int row;
        int sit;
        int klass;
        int price;

        void set_row();
        void set_sit();
};

#endif // PLAIN__PLACE_H
