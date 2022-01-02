#include <iostream>
#include <ctime>

using namespace std;

int* deleteElements(int*& array, int& sizeArray);
void printArray(int* array, int size);
void check_paire_elements(int* array, int size);
void shift(int* array, int sizeArray);

int main(void)
{
	srand(time(NULL));
	int sizeArray;
	do {
		cout << "Enter the size of array (more than 0): ";
		cin >> sizeArray;
	} while (sizeArray <= 0);
	int* array = new int[sizeArray];//�������� ������
	for (int i = 0; i < sizeArray; i++)
	{
		*(array + i) = rand() % 10 + 1;
	}
	cout << endl << "Array:" << endl;
	//�������� � ������ �� �������� ����� 5, �������� �� �� ���� �������� ��������:
	printArray(array, sizeArray);
	array = deleteElements(array, sizeArray);
	cout << endl << "Task #1:" << endl;
	//���������, �� � � ����� ����������� � ����� ������ ��������:
	printArray(array, sizeArray);
	cout << endl << "Task #2:" << endl;
	check_paire_elements(array, sizeArray);
	cout << endl << "Task #3:" << endl;
	//������� ���� ���� �������� ������(1, 2, 3, 4, 5 <-> 6, 7, 8, 9, 10; 11, 12, 13, 14, 15 <-> 16, 17, 18, 19, 20; ...):
	shift(array, sizeArray);
	printArray(array, sizeArray);
	delete[] array;
	return 0;
}

int* deleteElements(int*& array, int& sizeArray)
{
	int n = sizeArray;
	for (int i = 0; i < n; i++)
	{
		if (*(array + i) > 5)
		{
			sizeArray--;
		}
	}
	int* �hangedArray = new int[sizeArray];
	for (int i = 0, j = 0; i < n; i++)
	{
		if (*(array + i) <= 5)
		{
			*(�hangedArray + j) = *(array + i);
			j++;
		}
	}
	delete[] array;
	return �hangedArray;
}

void printArray(int* array, int sizeArray)
{
	for (int i = 0; i < sizeArray; i++)
	{
		cout << *(array + i) << " ";
	}
	cout << endl;
}

void check_paire_elements(int* array, int size)
{
	bool key = false;
	for (int i = 0; i < size - 2; i++)
	{
		if (*(array + i) % 2 == 0)
		{
			if (*(array + i + 1) % 2 == 0)
			{
				if (*(array + i + 2) % 2 == 0)
				{
					key = true;
					i = size;//��� ���������� ������ �� �����
				}
			}
		}
	}
	if (key == true)
	{
		cout << "The array has a sequence of 3 paired elements." << endl;// � ������� ���� ����� ������������������
	}
	else
	{
		cout << "There is no sequence of 3 paired elements in the array." << endl;// � ������� ��� ����� ������������������
	}
}

void shift(int* array,  int sizeArray) //������� �������� ��������
{
	if (sizeArray > 9)
	{
		return;
	}
	int x = 0;
	for (int i = 0; i < sizeArray - (sizeArray % 10); i += 10)
	{
		for (int j = i; j < i + 5; j++)
		{
			x = *(array + j);
			*(array + j) = *(array + j + 5);
			*(array + j + 5) = x;
		}
	}

}
