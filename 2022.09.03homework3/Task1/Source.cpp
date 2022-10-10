#include "Quaternion.h"

int main()
{
	Quaternion a (1, 1, 0, 0);
	Quaternion b (0, 0, 0, 1);
	cout << a / b;
	a /= b;
	cout << a;
	return 0;
}
