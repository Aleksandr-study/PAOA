#include <iostream> 
#include <ctime>

using namespace std;

int main(void)
{
	srand(time(NULL));
	const int N = 5;
	const int M = 4;
	int summ = 0;
	int notnegative = 0;
	float average[N];
	int array[N][M];
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			array[i][j] = rand() % 150 - 50;
			cout << array[i][j];
			cout << " ";
		}
		cout << endl;
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (array[i][j] > 0)
			{
				notnegative++;
				summ += array[i][j];
		    }
		}
		average[i] = summ / notnegative;
		cout << average[i] << "\n";
		summ = 0;
		notnegative = 0;
	}

}