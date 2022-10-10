#pragma once
#include <cmath>
#include <iostream>
using namespace std;

class Quaternion
{
private:
	double re = 0;
	double x = 0;
	double y = 0;
	double z = 0;
public:
	Quaternion(double re, double x, double y, double z);
	Quaternion(const Quaternion& object);
	void operator+=(Quaternion& object);
	void operator-=(Quaternion& object);
	void operator/=(Quaternion& object);
	void operator*=(Quaternion& object);
	void operator=(Quaternion& object);
	double abs();
	Quaternion& reverse();
	friend std::ostream& operator<<(std::ostream& stream, const Quaternion& object);
	friend std::istream& operator>>(std::istream& stream, const Quaternion& object);
	friend void swap(Quaternion& object1, Quaternion& object2);
	friend Quaternion& operator+(Quaternion& object1, Quaternion& object2);
	friend Quaternion& operator-(Quaternion& object1, Quaternion& object2);
	friend Quaternion& operator*(Quaternion& r1, Quaternion& r2);
	friend Quaternion& operator/(Quaternion& r1, Quaternion& r2);
};

