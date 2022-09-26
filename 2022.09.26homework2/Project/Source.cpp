#include<iostream>
#include "Array.h"

using namespace std;

int main() {
	Array a;
	Array b(15);
	for (int i = 0; i < 15; ++i) {
		a[i] = 1 + i;
		b[i] = 15 - i;
	}
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	b = a;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	return 0;
}