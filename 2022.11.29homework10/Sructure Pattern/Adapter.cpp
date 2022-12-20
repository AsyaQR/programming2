#include <iostream>
#include <string>

using namespace std;

class Human
{
public:
    string greeting()
    {
        return "Hello";
    }
};

class Cat
{
public:
    virtual ~Cat() {}
    virtual string greeting() = 0;
    virtual string translation() = 0;
};

class Adapter : public Cat
{
private:
    Human* p_human;
public:
    Adapter(Human* p) : p_human(p) {}
    ~Adapter()
    {
        delete p_human;
    }

    string greeting()
    {
        return "";
    }

    string translation()
    {
        return p_human->greeting() + "Feed me";
    }
};

int main()
{
    Human h;
    Adapter a(&h);
    Cat* p = reinterpret_cast<Cat*>(&a);
    cout << "Meow = " << p->translation() << endl;

    delete p;
    return 0;
}