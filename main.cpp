#include <iostream>
#include "Vector.h"

const int SIZE = 100;

void sieve(Vector<int>& values)
{
	unsigned int max = values.size();
	int i;

	for (int i = 2; i*i <= max; i++) 
	{
		if (values[i] != 0) 
			for (int j = i+i; j < max; j += i)
				values[j] = 0;
	}
}

int main()
{
	Vector <int> numbers(SIZE);
	
	//Fills vector with values 0 to vector size
	//initializeVector(numbers);
	for(int i = 0; i < SIZE; ++i)
		numbers[i] = i;

	//Should mark all non-prime numbers as 0
	sieve(numbers);
	
	//Cycles through a vector and prints all values != 0
	for(int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] != 0)
			std::cout << numbers[i] << " ";
	}
	
	return 0;
}
