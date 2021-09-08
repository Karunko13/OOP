#pragma once
#include <iostream>
#include "PairOfNumbers.h"

template<typename T>
class RangeArray
{
private:
	unsigned _size;
	T* _array;
public:

	RangeArray(const PairOfNumbers<int,T>& pair)
	{
		_size = pair.second - pair.first;
		_array = new T[_size];
	}

	~RangeArray()
	{
		delete[] _array;
	}

	unsigned Size() const
	{
		return _size;
	}
	T& operator[](int index)
	{
		index = index < 0 ? _size + index : index;

		return _array[index];
	}

	RangeArray(const RangeArray& other)
	{
		_size = other._size;
		_array = new T[_size];

		for (unsigned a = 0; a < _size; a++)
		{
			_array[a] = other._array[a];
		}
	}

	T& At(int index)
	{
		return (*this)[index];
	}
};