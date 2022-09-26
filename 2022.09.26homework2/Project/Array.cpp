#include "Array.h"

void Array::expand(int count)
{
	int* newdata = new int[count + capacity];
	for (int i = 0; i < capacity; ++i)
	{
		newdata[i] = data[i];
	}
	delete[] data;
	data = newdata;
	capacity += count;
}

int Array::ind(int index)
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

Array::Array(int capacity)
{
	this->capacity = capacity;
	count = 0;
	data = new int[capacity];
}

Array::Array(const Array& list)
{
	capacity = list.count;
	count = list.count;
	data = new int[list.count];
	for (int i = 0; i < list.count; ++i)
	{
		data[i] = list.data[i];
	}
}

Array::~Array()
{
	count = 0;
	capacity = 0;
	for (int i = 0; i < capacity; ++i)
	{
		data[i] = 0;
	}
	delete[] data;
}

void Array::pushend(int element)
{
	if (count == capacity)
	{
		expand(capacity);
	}
	data[count] = element;
	count++;
}

void Array::pushbegin(int element)
{
	if (count == capacity)
	{
		expand(capacity);
	}
	int* newdata = new int[capacity];
	newdata[0] = element;
	for (int i = 0; i < count; ++i)
	{
		newdata[i + 1] = data[i];
	}
	delete[] data;
	data = newdata;
	count++;
}

int& Array::operator[](int pos)
{
	return data[ind(pos)];
}

std::ostream& operator<<(std::ostream& stream, Array& list)
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
