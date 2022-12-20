#include <iostream>

using namespace std;

class Cat
{
public:
    virtual void care() = 0;
};

class AffectionateCat : public Cat
{
public:
    void care()
    {
        cout << "pick up and hug" << endl;
    }
};

class FearfulCat : public Cat
{
public:
    void care()
    {
        cout << "be sniffed and feed" << endl;
    }
};


class CatSeducer
{
private:
    Cat* p;
public:
    CatSeducer(Cat* pap) : p(pap) {}
    void caring()
    {
        p->care();
    }
};


int main()
{
    AffectionateCat a;
    CatSeducer c(&a);
    CatSeducer* p = &c;
    p->caring();
    delete p;
    return 0;
}