#include "Quaternion.h"

Quaternion::Quaternion(double re = 0, double x = 0, double y = 0, double z = 0)
{
	this->re = re;
	this->x = x;
	this->y = y;
	this->z = z;
}

Quaternion::Quaternion(const Quaternion& object)
{
	re = object.re;
	x = object.x;
	y = object.y;
	z = object.z;
}

void Quaternion::operator+=(Quaternion& object)
{
	*this = *this + object;
}

void Quaternion::operator-=(Quaternion& object)
{
	*this = *this - object;
}

void Quaternion::operator/=(Quaternion& object)
{
	*this *= object.reverse();
}

void Quaternion::operator*=(Quaternion& object)
{
	*this = *this * object;
}

void Quaternion::operator=(Quaternion& object)
{
	re = object.re;
	x = object.x;
	y = object.y;
	z = object.z;
}

double Quaternion::abs()
{
	return sqrt(re*re + x*x + y*y + z*z);
}

Quaternion& Quaternion::reverse()
{
	Quaternion res;
	double n = this->abs();
	res.re = re / n*n;
	res.x = -x / n*n;
	res.y = -y / n*n;
	res.z = -z / n*n;
	return res;
}
std::ostream& operator<<(std::ostream& stream, const Quaternion& object)
{
	stream << object.re << " + i * " << object.x << " + j * " << object.y << " + k * " << object.z << endl;
	return stream;
}

std::istream& operator>>(std::istream& stream, const Quaternion& object)
{
	stream >> object.re >> object.x >> object.y >> object.z;
	return stream;
}

Quaternion& operator+(Quaternion& object1, Quaternion& object2)
{
	Quaternion res;
	res.re = object1.re + object2.re;
	res.x = object1.x + object2.x;
	res.y = object1.y + object2.y;
	res.z = object1.z + object2.z;
	return res;
}

Quaternion& operator-(Quaternion& object1, Quaternion& object2)
{
	Quaternion res;
	res.re = object1.re - object2.re;
	res.x = object1.x - object2.x;
	res.y = object1.y - object2.y;
	res.z = object1.z - object2.z;
	return res;
}

Quaternion& operator*(Quaternion& r1, Quaternion& r2)
{
	Quaternion res;
	res.re = r1.re * r2.re - r1.x * r2.x - r1.y * r2.y - r1.z * r2.z;
	res.x = r1.re * r2.x + r1.x * r2.re + r1.y * r2.z - r1.z * r2.y;
	res.y = r1.re * r2.y + r1.y * r2.re + r1.z * r2.x - r1.x * r2.z;
	res.z = r1.re * r2.z + r1.z * r2.re + r1.x * r2.y - r1.y * r2.x;
	return res;
}

Quaternion& operator/(Quaternion& object1, Quaternion& object2)
{
	Quaternion res;
	res = object1 * object2.reverse();
	return res;
}

void swap(Quaternion* object1, Quaternion* object2)
{
	Quaternion* q;
	q = object1;
	object1 = object2;
	object2 = q;
}
