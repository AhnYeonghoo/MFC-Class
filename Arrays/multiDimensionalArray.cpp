#include <iostream>
using namespace std;

int main()
{
	const int numRows = 3;
	const int numColumns = 5;
	
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numColumns; col++)
		{
			cout << '[' << row << ']' << '[' << col << ']' << '\t';
		}
		cout << endl;
	}

	cout << endl;

	int arrays[numRows][numColumns] // row-major <-> column-major
	{
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15 },
	};
	
	for (const auto& value : arrays)
	{
		for (const auto& v : value)
		{
			cout << v << " ";
		}
		cout << endl;
	}

	cout << endl;
	
	return 0;
}