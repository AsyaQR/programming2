#include<iostream>

using namespace std;

template <typename T>
class Vector
{
private:
    T* data;
    int capacity;
    int count;

    void expand(int count)
    {
        T* newdata = new T[count + capacity];
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
        int num = data[posi];
        data[posi] = data[posj];
        data[posi] = num;
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


public:
    Vector(int capacity)
    {
        this->capacity = capacity;
        count = 0;
        data = new T[capacity];
    }

    Vector(const Vector& vec)
    {
        capacity = vec.count;
        count = vec.count;
        data = new T[vec.count];
        for (int i = 0; i < vec.count; ++i)
        {
            data[i] = vec.data[i];
        }
    }

    ~Vector()
    {
        count = 0;
        capacity = 0;
        for (int i = 0; i < capacity; ++i)
        {
            data[i] = 0;
        }
        delete[] data;
    }

    void pushend(T element)
    {
        if (count == capacity)
        {
            expand(capacity);
        }
        data[count] = element;
        count++;
    }

    void pushbegin(T element)
    {
        if (count == capacity)
        {
            expand(capacity);
        }
        T* newdata = new T[capacity];
        newdata[0] = element;
        for (int i = 0; i < count; ++i)
        {
            newdata[i + 1] = data[i];
        }
        delete[] data;
        data = newdata;
        count++;
    }

    void insert(T element, int position)
    {
        if (count == capacity)
        {
            expand(capacity);
        }
        T* newdata = new T[capacity];
        for (int i = 0; i < count + 1; ++i)
        {
            if (i < position)
            {
                newdata[i] = data[i];
            }
            else if (i == position)
            {
                newdata[i] = element;
            }
            else
            {
                newdata[i] = data[i - 1];
            }
        }
        delete[] data;
        data = newdata;
        count++;
    }

    T extractend()
    {
        count--;
        return data[count];
    }

    T extract(int position)
    {
        if (position < 1 || position > count)
        {
            pushbegin(position);
            return position;
        }
        else
        {
            T num = data[position - 1];
            for (int i = 0; i < count - 1; ++i)
            {
                if (i >= position - 1)
                {
                    data[i] = data[i + 1];
                }
            }
            count--;
            return num;
        }
    }

    T extractbegin()
    {
        T num = data[0];
        T* newdata = new T[capacity];
        for (int i = 0; i < count - 1; ++i)
        {
            newdata[i] = data[i + 1];
        }
        delete[] data;
        data = newdata;
        count--;
        return num;
    }

    T& operator[](int pos)
    {
        return data[ind(pos)];
    }

    void sort(int begin, int end)
    {
        if (end == 0) end = count - 1;
        int i = begin;
        int j = end;
        int mid = data[(begin + end) / 2];
        int temp;

        while (i <= j)
        {
            while (data[i] < mid)
                i++;
            while (data[j] > mid)
                j--;
            if (i <= j)
            {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
                i++;
                j--;
            }
        }
        if (j > begin)
            sort(begin, j);
        if (i < end)
            sort(i, end);
    }

    void print()
    {
        cout << "[" << count << "/" << capacity << "] {";
        if (count == 0)
        {
            cout << "EMPTY";
        }
        else
        {
            for (int i = 0; i < count - 1; ++i)
            {
                cout << data[i] << ", ";
            }
            cout << data[count - 1];
        }
        cout << "}" << endl;
    }
};

int main()
{
    Vector<int> v1(5);
    v1.pushend(123);
    v1.print();

    Vector<char> v2(10);
    v2.pushend('a');
    v2.print();

    return 0;
}