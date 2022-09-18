#include <iostream>
using namespace std;

struct Small {
    bool first;         
    char second;        
    short third;      
    int fourth;     
    long fifth;        
    float sixth;        
    double seventh;      
    long long eighth;      
};

struct Big {
    bool first;         
    long long second;        
    char third;      
    double fourth;     
    short fifth;        
    long sixth;        
    int seventh;      
    float eighth;      
};

int main() {
    Small min;
    cout << "min: " << sizeof(min) << endl;
    cout << "1 " << &min.first << endl;
    cout << "2 " << (int*)&min.second << endl;
    cout << "3 " << &min.third << endl;
    cout << "4 " << &min.fourth << endl;
    cout << "5 " << &min.fifth << endl;
    cout << "6 " << &min.sixth << endl;
    cout << "7 " << &min.seventh << endl;
    cout << "8 " << &min.eighth << endl;

    Big max;
    cout << "max: " << sizeof(max) << endl;
    cout << "1 " << &max.first << endl;
    cout << "2 " << &max.second << endl;
    cout << "3 " << (int*)&max.third << endl;
    cout << "4 " << &max.fourth << endl;
    cout << "5 " << &max.fifth << endl;
    cout << "6 " << &max.sixth << endl;
    cout << "7 " << &max.seventh << endl;
    cout << "8 " << &max.eighth << endl;

    return EXIT_SUCCESS;
};

/* С помощью интернета было установлено, что выравнивание
происходит следующим образом: к размеру предыдущего поля
прибавляется столько байт чтобы адрес последующего делился
на его размер. 

Минимальный размер это 32 байта, а минимален он, потому что
в таком случае вообще не добавляется байт. Если сложить все 
размеры полей получается как раз 32 байта (1+1+2+4+4+4+8+8).

А чтобы получить максимальный размер структуры, необходимо 
составить такой порядок полей, чтобы добавилось как можно
больше байт при выравнивании. Сначала надо поставить
восьмибайтовые поля после однобайтовых, чтобы добавилось по 
7 байт после каждого однобайтового поля. Затем после двухбайтового
поставить четырехбайтовое поле, чтобы добавилось еще 2 байта. И
останутся только четырехбайтовые. Максимальный размер 48 байт. */