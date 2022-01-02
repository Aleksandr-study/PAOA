#include <iostream> 
#include <ctime>

using namespace std;

int main(void)
{
	srand(time(NULL));
	int size_array = 5;
	int* pArray;
	pArray = new int[size_array];
	int quality = 0;
	for (int i = 0; i < size_array; i++)
	{
		pArray[i] = rand() % 100;
		cout << pArray[i] << " ";
	}
	cout << "\n";
	int min = pArray[0];
	for (int i = 1; i < size_array; i++)
	{
		if (pArray[i] < min)
		{
			min = pArray[i];
		}
	}
	for (int i = 0; i < size_array; i++)
	{
		if (pArray[i] == (min + 5))
		{
			quality++;
		}
	}
	cout << quality;
	delete[] pArray;
	return 0;
}