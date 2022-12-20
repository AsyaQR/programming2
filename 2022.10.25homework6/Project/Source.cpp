#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

string global_inname;

ifstream openinfile()
{
	string inname;
	try
	{
		cout << "Enter input file name: ";
		cin >> inname;
		ifstream infile(inname);
		if (!infile.is_open()) throw exception("infile did not open");
		global_inname = inname;
		return infile;
	}
	catch (exception err)
	{
		cout << err.what() << endl;
		openinfile();
	}
}

ofstream openoutfile()
{
	string outname;
	try
	{
		cout << "Enter output file name: ";
		cin >> outname;
		if (outname == global_inname) throw exception("cannot use this file to output");
		ofstream outfile(outname);
		if (!outfile.is_open()) throw exception("outfile did not open");
		return outfile;
	}
	catch (exception err)
	{
		cout << err.what() << endl;
		openoutfile();
	}
}

int main()
{
	ifstream infile = openinfile();
	ofstream outfile = openoutfile();

	string str;
	int n;
	int pren = 1;
	try
	{
		while (!infile.eof())
		{
			infile >> str;
			if (str[1] > 47 && str[1] < 58) throw ("there are not numbers in file");
			n = stoi(str);
			cout << n << " ";
			if (n > 46340) throw ("too big number");
			outfile << n * n << " ";
			if (pren == 0) throw ("devision by zero");
			outfile << double(n) / pren << endl;
			pren = n;
		}
	}
	catch (const char* error)
	{
		cout << error;
	}
	infile.close();
	outfile.close();

	return 0;
}