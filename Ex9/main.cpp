#include <iostream> 
#include <ctime>

using namespace std;

int main(void)
{
	srand(time(NULL));
	const int N = 5;
	const int M = 4;
	int A[N][M];
	int i, j;
	int summ[N];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			A[i][j] = rand() % 150 - 50;
			cout << A[i][j];
			cout << " ";
		}
		cout << endl;
	}
	for (i = 0; i < N; i++)
	{
		summ[i] = 0;
		for (j = 0; j < M - 1; j++)
		{
			summ[i] += A[i][j];
		}
	}
	cout << "\n";
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			A[i][M -1] = summ[i];
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	delete[] A;
	return 0;
}