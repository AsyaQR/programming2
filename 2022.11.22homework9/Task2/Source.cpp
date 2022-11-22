#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

class Dictionary
{
	map<string, string> dict;

public:
	void add(string eng, string ind)
	{
		dict[eng] = ind;
	}
	void fill(string file_name)
	{
		ifstream file(file_name);
		while (file)
		{
			string eng, ind;
			getline(file, eng, ' ');
			getline(file, ind);
			dict[eng] = ind;
		}
		file.close();
	}

	void eng_letter_search(char l, string language = "english")
	{
		if (language == "english")
		{
			cout << "English -> Indonesian: " << l << endl;
			map<string, string>::iterator it = dict.begin();
			while (it != dict.end())
			{
				if (it->first[0] == l && it->first[0] <= l)
					cout << it->first << " - " << it->second << endl;
				++it;
			}
		}
		else if (language == "indonesian")
		{
			cout << "Indonesian -> English: " << l << endl;
			map<string, string>::iterator it = dict.begin();
			while (it != dict.end())
			{
				if (it->second[0] == l)
					cout << it->first << " - " << it->second << endl;
				++it;
			}
		}
	}

	string search(string world, string language = "english")
	{
		if (language == "english")
		{
			map<string, string>::iterator it = dict.begin();
			while (it != dict.end())
			{
				if (it->first == world)
				{
					cout << it->first << " - " << it->second << endl;
					return it->second;
				}
				++it;
			}
		}
		else if (language == "indonesian")
		{

			map<string, string>::iterator it = dict.begin();
			while (it != dict.end())
			{
				if (it->second == world)
				{
					cout << it->first << " - " << it->second << endl;
					return it->first;
				}
				++it;
			}
		}
	}
	void file_translate(string in_name, string out_name, string language = "english")
	{
		ifstream in(in_name);
		ofstream out(out_name);
		while (!in.eof())
		{
			string word;
			getline(in, word, ' ');
			if (language == "english")
				out << dict[word] << " ";
			if (language == "indonesian")
				out << this->search(word, "indonesian") << " ";
		}
		in.close();
		out.close();
	}

	void print()
	{
		map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			cout << it->first << " - " << it->second << endl;
			++it;
		}
	}
};

int main()
{
	Dictionary dict;
	dict.fill("data.txt");
	dict.print();
	dict.file_translate("eng.txt", "ind.txt");
	return 0;
}

