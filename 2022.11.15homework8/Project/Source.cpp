#include <iostream>
#include <fstream>

using namespace std;

template<typename Type1, typename Type2, typename Type3>
Type1 swap(Type2* a, Type3* b)
{
	Type2* c;
	a = c;
	a = b;
	b = c;
}

template<typename Type1, typename Type2, typename Type3>
class Shell
{
private:
	Type1* foo;
public:
	Shell(Type1(*f)(Type2, Type3))
	{
		foo = *f;
	}
	void operator()(Type2 a, Type3 b)
	{
		swap(a, b);
		ofstream file("log.txt");
		file << a << " " << b << cout;
		file.close();
	}
};


int main()
{
	Shell<void, int, int> shell_swap(swap);
	return 0;
}