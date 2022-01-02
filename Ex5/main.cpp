#include <iostream> 
#include <ctime>

#define N 10
using namespace std;

int main(void)
{
	srand(time(NULL));
	int Arr[N]= { 0 };
	bool flag = true;
	for (int i = 0; i < N; i++)
	{
		Arr[i] = rand() % 100;
		cout << Arr[i] << " ";
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j <N; j++)
		{
			if (Arr[i] == Arr[j])
			{
				cout << "There are the same elements in this array";
				i = N;
				j = N;
				flag = false;
		    }
		}
	}
	if (flag)
	{
		cout << "There are not the same elements in this array";
	}
	return 0;
}