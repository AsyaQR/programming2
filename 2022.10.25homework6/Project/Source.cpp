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
	try
	{
		cout << "Enter output file name: ";
		cin >> outname;
		if (outname == inname) throw ("cannot use this file to output");
		ifstream infile(inname);
		if (!infile.is_open()) throw ("infile did not open");
		ofstream outfile(outname);
		if (!outfile.is_open()) throw ("outfile did not open");

		string str;
		int n;
		int pren = 1;
		while (!infile.eof())
		{
			infile >> str;
			if (str[0] > 47 || str[0] > 57) throw ("there are not numbers in file");
			n = stoi(str);
			if (n > 46340) throw ("too big number");
			outfile << n * n << " ";
			if (pren == 0) throw ("devision by zero");
			outfile << double(n) / pren << endl;
			pren = n;
		}

		infile.close();
		outfile.close();
	}
	catch(const char* error)
	{
		cout << error;
	}

	return 0;
}