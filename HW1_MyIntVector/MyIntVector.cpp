//2019203102 À¯Áö¼º

#include <cstdlib>
#include <stdlib.h>
#include <algorithm>   
#include <cassert>       
#include "MyIntVector.h"
#include <iostream>
using namespace std;

MyIntVector::MyIntVector()
{
	data = new int[DEFAULT_CAPACITY];
	space = DEFAULT_CAPACITY;
	used = 0;
}

MyIntVector::MyIntVector(const MyIntVector& v)
{
	data = new int[v.space];
	space = v.space;
	used = v.used;
	copy(v.data, v.data + used, data);
}

MyIntVector::~MyIntVector()
{
	delete[] data;
}

void MyIntVector::pop_back()
{
	if (used == 0)
	{
		cout << "size is ZERO!";
		return;
	}

	data[--used] = 0;
}

void MyIntVector::push_back(int x)
{
	if (used == space)
		reserve(used + 1);
	data[used] = x;
	++used;
}


void MyIntVector::reserve(size_t n)
{
	if (n < 0)
		throw "Error! (reserve) : capacity(space) should not lower than 0";
	
	int* larger_array;

	if (n == space)
		return;
	if (n < used)
		n = used;

	larger_array = new int[n];
	copy(data, data + used, larger_array);
	delete [] data;
	data = larger_array;
	space = n;
}

bool MyIntVector::is_empty() const
{
	if (used == 0)
		return true;
	else
		return false;
}

void MyIntVector::clear()
{
	used = 0;
	reserve(DEFAULT_CAPACITY);
}

void MyIntVector::operator=(const MyIntVector& source)
{
	int* new_data;

	if (this == &source)
		return;

	if (space != source.space)
	{
		new_data = new int[source.space];
		delete[] data;
		data = new_data;
		space = source.space;
	}

	used = source.used;
	copy(source.data, source.data + used, data);
}

void MyIntVector::operator+=(const MyIntVector& addend)
{
	if (used + addend.used > space)
		reserve(used + addend.used);

	copy(addend.data, addend.data + addend.used, data + used);
	used += addend.used;
}

int MyIntVector::operator[](int n)
{
	if (n < used && 0 <= n)
		return this->data[n];
	else
	{
		cout << "\nError! ([] operator) : please check range\n";
		exit(-1);
	}
}

MyIntVector MyIntVector::operator+(const MyIntVector& source)
{
	if (this->used != source.used)
	{
		throw "Error! (+ operator) : size are different!\n";
	}
	else 
	{
		MyIntVector temp;
		for (int i = 0; i < used; i++)
		{
			temp.push_back(this->data[i] + source.data[i]);
		}
		return temp;
	}
}

MyIntVector MyIntVector::operator-(const MyIntVector& source)
{
	if (this->used != source.used)
	{
		throw "Error! (- operator) : size are different!\n";
	}
	else
	{
		MyIntVector temp;
		for (int i = 0; i < used; i++)
		{
			temp.push_back(this->data[i] - source.data[i]);
		}
		return temp;
	}
}

int MyIntVector::operator*(const MyIntVector& source)
{
	if (this->used != source.used)
	{
		throw "Error! (* operator) : size are different!\n";
	}
	else
	{
		int temp = 0;
		for (int i = 0; i < used; i++)
		{
			temp += this->data[i] * source.data[i];
		}
		return temp;
	}
}

MyIntVector MyIntVector::operator-()
{
	MyIntVector temp;
	for (int i = 0; i < used; i++)
	{
		temp.push_back(this->data[i] * -1);
	}
	return temp;
}

bool MyIntVector::operator==(const MyIntVector& source)
{
	if (this->used != source.used)
		return false;
	
	for (int i = 0; i < used; i++)
	{
		if (this->data[i] != source.data[i])
			return false;
	}
	
	return true;
}

MyIntVector MyIntVector::operator()(int n)
{
	MyIntVector temp;

	for (int i = 0; i < used; i++)
	{
		temp.push_back(n);
	}

	return temp;
}
