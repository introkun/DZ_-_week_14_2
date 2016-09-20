#include <iostream>
#include <ctime>

int* newArray(int size)
{
	return new int[size];
}
void initializationArray(int* arr, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = rand() % 20 - 10;
	}
}
void outArray(int* arr, int size)
{
	std::cout << "[" << size << "] = {";
	for (int i = 0; i < size; i++)
	{
		std::cout << *(arr + i) << ", ";
	}
	std::cout << "};" << std::endl;
}
void deleteArray(int* arr)
{
	delete[] arr;
}
int* addElementsToArray(int*arr, int* size, int element)
{
	(*size)++;
	int* newArr = newArray(*size);
	for (int i = 0; i < *size; i++)
	{
		if (i == *size - 1)
		{
			*(newArr + i) = element;
		}
		else
		{
			*(newArr + i) = *(arr + i);
		}
	}
	deleteArray(arr);
	arr = nullptr;
	return arr = newArr;
}
void sortArrayToMoreArray(int* mainArray, int size)
{
	int sizeArrayNegativeNumbers = 0;
	int sizeArrayPositiveNumbers = 0;
	int sizeArrayZero = 0;
	int* arrayNegativeNumbers = nullptr;
	int* arrayPositiveNumbers = nullptr;
	int* arrayZero = nullptr;
	for (int i = 0; i < size; i++)
	{
		if (*(mainArray + i) < 0)
		{
			arrayNegativeNumbers = addElementsToArray(arrayNegativeNumbers, &sizeArrayNegativeNumbers, *(mainArray + i));
		}
		else if (*(mainArray + i) > 0)
		{
			arrayPositiveNumbers = addElementsToArray(arrayPositiveNumbers, &sizeArrayPositiveNumbers, *(mainArray + i));
		}
		else
		{
			arrayZero = addElementsToArray(arrayZero, &sizeArrayZero, *(mainArray + i));
		}
	}
	std::cout << "arrayNegativeNumbers";
	outArray(arrayNegativeNumbers, sizeArrayNegativeNumbers);
	std::cout << "arrayPositiveNumbers";
	outArray(arrayPositiveNumbers, sizeArrayPositiveNumbers);
	std::cout << "arrayZero";
	outArray(arrayZero, sizeArrayZero);
}
int main()
{
	const int size = 20;
	int mainArr[size];
	initializationArray(mainArr, size);
	std::cout << "mainArr";
	outArray(mainArr, size);
	sortArrayToMoreArray(mainArr, size);
}