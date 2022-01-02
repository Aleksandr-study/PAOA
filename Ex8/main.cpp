#include <iostream>
#include <ctime>
using namespace std;

int main(void)
{
	srand(time(NULL));
	const int N = 5;
	int matrix[N][N];
	int i;
	int j;
	int summ = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			matrix[i][j] = rand() % 150 - 50;
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	long long int multi = 1;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if ((i == j) && (matrix[i][j] != 0))
			{
				multi *= matrix[i][j];
			}
		}
		if (matrix[i][N - 1 - i] != 0)
		{
			multi *= matrix[i][N - 1 - i];
		}
	}
	cout << multi;
	return 0;
}