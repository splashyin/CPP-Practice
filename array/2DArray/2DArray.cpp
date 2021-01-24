#include <iostream>

int main()
{
	// Initialise an array of ints
	// allocate 200 bytes of memory
	int* array = new int[50];

	// Store 50 int pointers, 200 bytes
	int** a2d = new int*[50];

	for (int i = 0; i < 50; i++)
	{
		a2d[i] = new int[50];
	}

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			a2d[i][j] = 2;
		}
	}

	// instead of assign a 2D array
	// using a 1D array will reduce more cache miss
	// because 2D arrays are not guaranteed to store closely
	int* a1d = new int[50 * 50];
	for (int y = 0; y < 50; y++)
	{
		for (int x = 0; x < 50; x++)
		{
			// each time y increases we jump 50 elements
			// which equals to go to another row in 2D array's grid
			// but this way the data is guaranteed to be close to each other
			// hense the performance increase
			a1d[x + y * 50] = 2;
		}
	}

	std::cin.get();
}
