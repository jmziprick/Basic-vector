#ifndef _VECTOR_H
#define _VECTOR_H

#include <cassert>
#include <algorithm>

using namespace std;

template <class T>
class Vector
{
	public:
		typedef T* iterator;
		typedef T value_type;

		Vector() : buffer(0), mySize(0), myCapacity(0){}

		Vector(unsigned int capacity) : buffer(0)
		{
			resize(capacity);
		}

		Vector(unsigned int size, T initial) : buffer(0)
		{
			resize(size);
			fill(buffer, buffer + size, initial);
		}

		Vector(Vector& v) : buffer(0)
		{
			resize(v.size());
			copy(v.begin(), v.end(), begin());
		}

		~Vector()
		{
			delete [] buffer;
		}

		T& back() const
		{
			return buffer[mySize-1];
		}

		T& front() const
		{
			return buffer[0];
		}
		
		iterator begin(){return buffer;}
		iterator end(){return begin() + mySize;}

		int capacity(){return myCapacity;}
		int size(){return mySize;}

		bool empty(){return mySize == 0;}

		void pop_back(){mySize--;}

		void push_back(T);

		void reserve(unsigned int);

		void resize(unsigned int newSize)
		{
			reserve(newSize);
			mySize = newSize;
		}

		T& operator [](unsigned int index)
		{
			return buffer[index];
		}
		
		T& at(unsigned int index)
		{
			return buffer[index];
		}

	protected:
		unsigned int mySize;
		unsigned int myCapacity;
		T* buffer;
};

template<class T>
void Vector<T>::reserve(unsigned int newCap)
{
	if(buffer == 0)
	{
		mySize = 0;
		myCapacity = 0;
	}

	if(newCap <= myCapacity)
		return;

	T* newBuffer = new T[newCap];
	assert(newBuffer);
	copy(buffer, buffer + mySize, newBuffer);

	myCapacity = newCap;
	delete [] buffer;
	buffer = newBuffer;
}

template <class T>
void Vector<T>::push_back(T value)
{
	if(mySize >= myCapacity)
		reserve(myCapacity + 5);

	buffer[mySize++] = value;
}

#endif
