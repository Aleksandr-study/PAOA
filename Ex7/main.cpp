#include <iostream>
#include <ctime>
using namespace std;

int main(void)
{
	srand(time(NULL));
	const int N = 5;
	int matrix[N][N];
	int i, j;	
	int summ = 0;
	int multi = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			matrix[i][j] = rand() % 150 - 50;
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	int min = matrix[0][0];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (min > matrix[i][j])
			{
				min = matrix[i][j];
			}
			if (matrix[i][j] > 0)
			{
				summ += matrix[i][j];
			}
		}
	}
	cout << min << "\n";
	multi = min * summ;
	cout << multi;
	return 0;
}
