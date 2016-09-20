#include <iostream>

int* newArray(int size)
{
	return new int[size];
}
void initializationArray(int* arr, int size)
{
	srand(25);
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void outArray(int* arr, int size)
{
	std::cout << "arr[" << size << "] = {";
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
int* deleteSimpleNumbersToArray(int* arr, int* size)
{
	int countSimpleNumbers = 0;
	for (int i = 0; i < *size; i++)
	{
		for (int j = 2; j <= *(arr + i) / 2; j++)
		{
			if (*(arr + i) % j == 0)
			{
				break;
			}
			if (j == *(arr + i) / 2)
			{
				int* arr2 = newArray(*size - 1);
				for (int k = 0, l = 0; k < *size; k++, l++)
				{
					if (k == i)
					{
						k++;
					}
					*(arr2 + l) = *(arr + k);
				}
				(*size)--;
				deleteArray(arr);
				arr = nullptr;
				arr = arr2;
			}
		}
	}
	return arr;
}

int main()
{
	int* arr;
	int size;
	std::cout << "Vvedite razmer massiva: ";
	std::cin >> size;
	arr = newArray(size);
	initializationArray(arr, size);
	outArray(arr, size);
	arr = deleteSimpleNumbersToArray(arr, &size);
	outArray(arr, size);
	return 0;
}