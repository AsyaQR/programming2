#include <iostream>
#include <vector>
#include <ctime> 
#include <thread>

using namespace std;

int f(int a, int b)
{
	 for (int i = 1; i <= max(a, b); ++i)
	 {
		 if (a % i == 0 and b % i == 0)
			 return i;
	 }
}

void vectorf(vector<int> a, vector<int> b)
{
	for (long int i = 0; i < 1750000; ++i)
	{
		a[i] = f(a[i], b[i]);
	}
	cout << "done" << endl;
}

int main()
{
	srand(time(0));
	vector<int> a(1750000);
	vector<int> b(1750000);
	vector<int> c(1750000);
	vector<int> d(1750000);
	for (long int i = 0; i < 1750000; ++i)
	{
		a[i] = 1 + rand() % 1000;
	}
	for (long int i = 0; i < 1750000; ++i)
	{
		b[i] = 1 + rand() % 1000;
	}
	for (long int i = 0; i < 1750000; ++i)
	{
		c[i] = 1 + rand() % 1000;
	}
	for (long int i = 0; i < 1750000; ++i)
	{
		d[i] = 1 + rand() % 1000;
	}
	unsigned int start_time = clock();
	vectorf(a, b);
	vectorf(c, d);
	/*thread S1(vectorf, a, b);
	thread S2(vectorf, c, d);
	S1.join();
	S2.join();*/
	unsigned int end_time = clock();
	cout << "runtime = " << end_time - start_time << endl;
	return 0;
}
/*
done
done
runtime = 550
--------------
done
done
runtime = 461
*/