
#include<iostream>
#include<fstream>
using namespace std;

template<typename t>
class Vector
{
public:
	t* data;
	int capacity;
	int count;
	Vector<t>(int _capacity)
	{
		capacity = _capacity;
		count = 0;
		data = new t[capacity];
	}
	void expand(int count = 1)
	{
		t* newdata = new t[count + capacity];
		for (int i = 0; i < capacity; ++i)
		{
			newdata[i] = data[i];
		}
		delete[] data;
		data = newdata;
		capacity += count;
	}
	void swap(int posi, int posj)
	{
		t m = data[ind(posi)];
		data[ind(posi)] = data[ind(posj)];
		data[ind(posj)] = m;
	}
	int ind(int index)
	{
		if (index < 0)
		{
			pushbegin(0);
			return 0;
		}
		if (index >= count)
		{
			pushend(0);
			return count - 1;
		}
		return index;
	}

	Vector<t>(const Vector<t>& list)
	{
		capacity = list.count;
		count = list.count;
		data = new t[list.count];
		for (int i = 0; i < list.count; ++i)
		{
			data[i] = list.data[i];
		}
	}
	~VectorM<t>()
	{
		count = 0;
		capacity = 0;
		delete[] data;
	}

	void pushend(t element)
	{
		if (count == capacity)
		{
			expand(capacity);
		}
		data[count] = element;
		count++;
	}
	void pushbegin(t element)
	{
		if (count == capacity)
		{
			expand(capacity);
		}
		pushend(0);
		for (int i = count - 1; i > 0; --i)
		{
			data[i] = data[i - 1];
		}
		data[0] = element;
	}

	void insert(t element, int position)
	{
		if (position <= 0)
		{
			pushbegin(element);
		}
		else if (position >= (count - 1))
		{
			pushend(element);
		}
		else
		{
			pushend(0);
			for (int i = count - 1; i > position; --i)
			{
				data[i] = data[i - 1];
			}
			data[position] = element;
		}
	}
	t extractbegin()
	{
		t m = data[0];
		for (int i = 0; i < (count - 1); ++i)
		{
			data[i] = data[i + 1];
		}
		count--;
		return m;
	}
	t extractend()
	{
		count--;
		return data[count];
	}
	t extract(int position)
	{
		if (position <= 0)
		{
			return extractbegin();
		}
		else if (position >= (count - 1))
		{
			return extractend();
		}
		else
		{
			t m = data[position];
			for (int i = position; i < (count - 1); ++i)
			{
				data[i] = data[i + 1];
			}
			count--;
			return m;
		}
	}

	t& operator[](int pos)
	{
		return data[ind(pos)];
	}


	friend std::ostream& operator<<(std::ostream& stream, const Vector<t>& list)
	{
		stream << "[" << list.count << "/" << list.capacity << "] {";
		if (list.count == 0)
		{
			stream << "EMPTY";
		}
		else
		{
			for (int i = 0; i < list.count - 1; ++i)
			{
				stream << list.data[i] << ", ";
			}
			stream << list.data[list.count - 1];
		}
		stream << "}";
		return stream;
	}
	friend std::istream& operator>>(std::istream& stream, const Vector<t>& list)
	{
		for (int i = 0; i < list.capacity; ++i)
		{
			stream >> list.data[i];
		}
		return stream;
	}

	VectorM operator=(const VectorM<t>& arr)
	{
		if (&arr == this)
		{
			return *this;
		}
		this->count = arr.count;
		this->capacity = arr.capacity;
		delete[] data;
		data = new t[capacity];
		for (int i = 0; i < this->count; ++i)
		{
			data[i] = arr.data[i];
		}
		return *this;
	}

};
template<class T>
void write_in_file(Vector<T>& s, string st)
{
	ofstream file(st);
	//file.seekg(0);
	int n = (s.count) * (sizeof s.data[0]);
	file << s.count;
	file.write(reinterpret_cast<char*>(s.data), n);
	file.close();
}

template<class T>
Vector<T> read_from_file(ifstream& file)
{
	file.clear();
	file.seekg(0);
	int b = 0;
	file >> b;
	Vector<T> v(b);
	char* ch = new char[b * sizeof(T) + 1];
	ch[b * sizeof(T)] = 0;
	file.read(ch, b * sizeof(T));
	v.count = b;
	v.data = reinterpret_cast<T*>(ch);
	return v;
	file.close();
}

int main(int argc, char** argv)
{
	Vector<int> s(5);
	s[0] = 123;
	s[1] = 1221;
	s[2] = 5;
	s[3] = 8;
	s[4] = 99;
	write_in_file(s, "Text.txt");

	ifstream in("Text.txt");

	cout << read_from_file<int>(in);
	return 0;
}