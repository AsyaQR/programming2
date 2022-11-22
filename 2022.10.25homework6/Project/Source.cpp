#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string inname;
	string outname;
	cout << "Enter input file name: ";
	cin >> inname;
	cout << "Enter output file name: ";
	cin >> outname;
	ifstream infile(inname);
	ofstream outfile(outname);

	string str;
	int n;
	int pren = 1;
	while (!infile.eof())
	{
		infile >> str;
		n = stoi(str);
		outfile << n * n << " ";
		outfile << double(n) / pren << endl;
		pren = n;
	}
	infile.close();
	outfile.close();

	return 0;
}