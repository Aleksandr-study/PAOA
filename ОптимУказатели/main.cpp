#include <iostream>

using namespace std;

void sdvig(int* M, int N, int start);

int main(void)
{
	setlocale(LC_ALL, "rus");
	int sizeArray;
	while (true)
	{
		cout << "������� �����������: ";
		cin >> sizeArray;
		if (sizeArray < 10)
		{
			cout << "����������� ������ ��� ������� 10!" << endl;
		}
		else
		{
			break;
		}
	}
	cout << "������: " << endl;
	int* array = new int[sizeArray];
	for (int i = 0; i < sizeArray; i++)
	{
		*(array + i) = rand() % 100;
		cout << *(array + i) << " ";
	}
	int start;
	for (int k = 10; k <= sizeArray; k += 10)
	{
		start = k - 10;
		sdvig(array, k, start);
	}
	cout << endl << "������: " << endl;
	for (int i = 0; i < sizeArray; i++)
	{
		cout << *(array + i) << " ";
	}
	return 0;
}

void sdvig(int* array, int N, int start) //������� �������� ��������
{
	for (int i = start; i < N - 5; i++)
	{
		int temp = *(array + i + 5);
		*(array + i + 5) = *(array + i);
		*(array + i) = temp;
	}
}
