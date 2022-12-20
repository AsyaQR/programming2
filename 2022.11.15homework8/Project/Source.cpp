#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void print()
{
	cout << "1";
}

template<typename Type>
using ffree = Type (*)();

class Shell
{
private:
	ffree<void> foo;
	ofstream file;
public:
	Shell(ffree<void> f)
	{
		file = ofstream("log.txt");
		foo = f;
	}
	void operator()()
	{
		foo();
		file << clock() << endl;
	}
	~Shell()
	{
		file.close();
	}
};


int main()
{
	ffree<void> func = &print;
	Shell shell_swap(func);
	shell_swap();
	shell_swap();
	shell_swap();
	shell_swap();
	return 0;
}