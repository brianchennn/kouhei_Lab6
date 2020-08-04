#include "Vector.h"
#include <cmath>

Vector::Vector()
{
	arr = new float[0];
	arrSize = 0;
	currentIndex = 0;
}

Vector::Vector(int size)
{
	//TODO: Dynamic allocate array by the size  
	arr = new float[size];
	arrSize = size;
}

Vector::Vector(const Vector& V)
{
	//TODO: Copy Constructor
	arr = V.arr;
	arrSize = V.arrSize;
	currentIndex = V.currentIndex;
}

Vector::~Vector()
{
	delete[] arr;
}

void Vector::AddNumbertoArr(float number)
{
	//TODO: Input a number into array
	arr[currentIndex] = number;
}

int Vector::getSize()
{
	//TODO: Return the array size
	return arrSize; //Remove this line
}
float Vector::length()
{
	//TODO: Compute the length of vector and return it
	int n = 0;
	for (int i = 0; i < arrSize; i++)n += (arr[i] * arr[i]);
	n = sqrt(n);
	return n; //Remove this line
}

Vector Vector::normalize()
{
	//TODO: Normalize the vector and return it
	Vector V(arrSize);
	int n;
	float l = length();
	for (int i = 0; i < arrSize; i++) {
		arr[i] = arr[i] / l;
		V.arr[i] = arr[i];
	}
	return V;
	//return Vector(); //Remove this line
}

Vector  Vector::operator+(const Vector &v)
{
	//TODO: Overload the plus operator +. 
	//Then we can use more intuitively way to add our vector (like v1 + v2).
	//Return the result of v1 + v2
	
	Vector V(v.arrSize);
	for (int i = 0; i < arrSize; i++)V.arr[i] = arr[i] + v.arr[i];
	return V;
	//return Vector(); //Remove this line
}

Vector  Vector::operator=(const Vector &v)
{
	//TODO: Overload the assign operator =.
	//Then we can use more intuitively way to assign out vector (like v1 = v2).
	Vector V(v.arrSize);
	arrSize = v.arrSize;
	for (int i = 0; i < v.arrSize; i++){
		V.arr[i] = v.arr[i];
		arr[i] = v.arr[i];
	}
	return V;
	//return Vector(); //Remove this line
}

Vector  Vector::operator-(const Vector &v)
{
	//TODO: Overload the subtract operator -.
	//Then we can use more intuitively way to subtract out vector (like v1 - v2).
	//Return the result of v1 - v2
	Vector V(v.arrSize);
	for (int i = 0; i < arrSize; i++)V.arr[i] = arr[i] - v.arr[i];
	
	return V;
	//return Vector(); //Remove this line
}

float  Vector::operator*(const Vector &v)
{
	//TODO: Overload the operator * as dot product.
	//Return the dot product result of two vector
	int n = 0;
	for (int i = 0; i < arrSize; i++) {
		n += arr[i] * v.arr[i];
	}
	return n; //Remove this line
}

ifstream & operator>>(ifstream & in, Vector &v)
{
	//TODO: Overload the >> operator.
	//Read the input.txt file and store vector in v
	in >> v.arrSize;
	for (int i = 0; i < v.arrSize; i++) {
		int n ;
		in >> n;
		v.AddNumbertoArr(n);
		v.currentIndex++;
	}
	return in;
}

ostream & operator<<(ostream & out, const Vector & v)
{
	//TODO: Overload the << operator.
	//Output the vector v
	out << "(";
		for (int i = 0; i < v.arrSize; i++) {
			if (i < v.arrSize-1) {
				out << v.arr[i] << ",";
			}
			if (i == v.arrSize - 1)
				out << v.arr[i];
	}
		out << ")";
	return out;
}
