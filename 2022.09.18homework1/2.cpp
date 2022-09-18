#include <iostream>
using namespace std;

class A {
    friend class AA;
    int x = 0;
    char y = 0;
    double z = 0;
    void printX(){
        cout << "x: " << x << endl;
    }
    void printY(){
        cout << "y: " << y << endl;
    }
    void printZ(){
        cout << "z: " << z << endl;
    }
};

class AA {
public:
    void change_x(A& a, int n) {
        a.x = n;
    }
    void change_y(A& a, char n) {
        a.y = n;
    }
    void change_z(A& a, double n) {
        a.z = n;
    }
    void print_x(A a) {
        void (A::*ptx)() = &A::printX; // указатель на функцию-член
        (&a->*ptx)();
    }
    void print_y(A a) {
        void (A::*pty)() = &A::printY; // указатель на функцию-член
        (&a->*pty)();
    }
    void print_z(A a) {
        void (A::*ptz)() = &A::printZ; // указатель на функцию-член
        (&a->*ptz)();
    }
};

int main() {
    A a;
    AA aa;
    aa.change_x(a, 2);
    aa.change_y(a, 'a');
    aa.change_z(a, 5.23);
    aa.print_x(a);
    aa.print_y(a);
    aa.print_z(a);
    return EXIT_SUCCESS;
}

/* Путем поиска информации в интернете выяснила, что, чтобы
воспользоваться указателем на метод (функцию-член), надо, 
чтобы метод был публичным или находился в дружественном классе.
Поэтому создала дружественный класс и уже в нем создавала 
указатели на методы. */