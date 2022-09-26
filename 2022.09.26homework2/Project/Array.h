#pragma once
#include<ostream>

class Array
{
private:
	int* data;
	int capacity;
	int count;
	void expand(int count = 1);
	int ind(int index);

public:
	Array(int capacity = 10);
	Array(const Array& list);
	~Array();
	void pushend(int element);
	void pushbegin(int element);
	int& operator[](int pos);

	friend std::ostream& operator<<(std::ostream& stream, Array& list);
};


