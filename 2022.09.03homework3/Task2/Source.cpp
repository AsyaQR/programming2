#include<iostream>
using namespace std;

template<typename Type>
bool defcompare(Type a, Type b)
{
    if (a > b)
        return true;
    else
        return false;
}

template<typename Type>
void defsort(Type* arr, bool(*compare)(Type, Type), int low, int high)
{
    int i = low;
    int j = high;
    Type pivot = arr[(i + j) / 2];

    while (not compare(i, j))
    {
        while (not compare(arr[i], pivot))
            i++;
        while (compare(arr[j], pivot))
            j--;
        if (not compare(i, j))
        {
            Type temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (compare(j, low))
        defsort<Type>(arr, *compare, low, j);
    if (not compare(i, high))
        defsort<Type>(arr, *compare, i, high);
}

//template<typename Type, bool(*compare)(Type, Type) = nullptr, void(*sorted)(Type* arr, bool(*compare)(Type, Type), int low, int high) = nullptr> эта штука все таки не работает
template<typename Type>
void sort(Type* arr, int n, bool(*compare)(Type, Type), void(*sorted)(Type* arr, bool(*compare)(Type, Type), int low, int high))
{
    int high = n;
    int low = 0;
    if (compare == nullptr)
    {
        compare = defcompare;
    }
    if (sorted == nullptr)
    {
        sorted = defsort;
    }
    sorted(arr, compare, low, high);
}

int main()
{
    int* a = new int[10];
    for (int i = 0; i < 10; ++i)
    {
        a[i] = 10 - i;
    }
    for (int i = 0; i < 10; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    sort<int>(a, 10, defcompare, defsort);
    for (int i = 0; i < 10; ++i)
    {
        cout << a[i] << " ";
    }
    return 0;
}