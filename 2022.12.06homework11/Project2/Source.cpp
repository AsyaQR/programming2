#include<fstream>
#include<iostream>
#include <algorithm>

using namespace std;

bool comp(const int& a, const int& b)
{
	return a > b;
}

int main()
{
	ifstream infile("int.txt");
	int* numbers = new int[13131];

	for (int i = 0; i < 13131; ++i)
	{
		infile >> numbers[i];
	}
	sort(numbers, numbers + 13131, comp);
	ofstream outfile("outnob2.txt");
	for (int i = 0; i < 13131; ++i)
	{
		outfile << numbers[i] << ' ';
	}
	delete[] numbers;
	infile.close();
	outfile.close();
	return 0;
}