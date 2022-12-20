//--------Prototype----------

#include <iostream>
#include <string>

using namespace std;

struct Shop
{
    string street;
    string city;
    int house;
};

class Employee
{
    string name;
    Shop* shop;

    Employee(string n, Shop* o) : name(n), shop(o) {}
    friend class EmployeeFactory;

public:
    Employee(const Employee& rhs) : name{ rhs.name }, shop{ new Shop{*rhs.shop} }
    { }

    Employee& operator=(const Employee& rhs)
    {
        if (this == &rhs) return *this;
        name = rhs.name;
        shop = new Shop{ *rhs.shop };
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Employee& o)
    {
        return os << o.name << " works at " << o.shop->street << " " << o.shop->house << " " << o.shop->city;
    }
};

class EmployeeFactory {
    static Employee salesman;
    static Employee manager;
    static unique_ptr<Employee> NewEmployee(string n, Employee& proto) {
        auto e = make_unique<Employee>(proto);
        e->name = n;
        return e;
    }

public:
    static unique_ptr<Employee> NewSalsesMan(string name) {
        return NewEmployee(name, salesman);
    }
    static unique_ptr<Employee> NewManager(string name) {
        return NewEmployee(name, manager);
    }
};

Employee EmployeeFactory::salesman{ "", new Shop{"Regent Street", "Boston", 12}};
Employee EmployeeFactory::manager{ "", new Shop{"Mayfair", "London", 2}};

int main() {
    auto ann = EmployeeFactory::NewSalsesMan("Ann");
    auto tim = EmployeeFactory::NewManager("Tim");
    cout << *tim << endl << *ann << endl;
    return EXIT_SUCCESS;
}