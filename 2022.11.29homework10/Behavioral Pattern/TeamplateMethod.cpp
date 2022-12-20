#include <iostream>
using namespace std;

class Base
{
    void a()
    {
        cout << "alpha";
    }
    void b()
    {
        cout << "beta";
    }
    void c()
    {
        cout << "gamma";
    }
    virtual void ph1() = 0;
    virtual void ph2() = 0;
public:
    void print()
    {
        a();
        b();
        ph1();
        ph2();
        c();
    }
};

class One : public Base
{
    void ph1()
    {
        cout << "ten";
    }
    void ph2()
    {
        cout << "twenty";
    }
};

class Two : public Base
{
    void ph1()
    {
        cout << "forty";
    }
    void ph2()
    {
        cout << "fifty";
    }
};

int main()
{
    Base* array[2];
    One o;
    Two t;
    array[0] = &o;
    array[1] = &t;
    for (int i = 0; i < 2; i++)
    {
        array[i]->print();
        cout << endl;
    }
}