#include <iostream>
using namespace std;


void printArray(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int mainSelectionSort()
{
	const int length = 5;
	int values[5]{ 3, 5, 2, 1,4 };

	printArray(values, length);

	cout << endl;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length ; j++)
		{
			if (values[i] < values[j])
			{
				int temp = values[i];
				values[i] = values[j];
				values[j] = temp;
			}
		}
	}

	printArray(values, length);

	return 0;
}