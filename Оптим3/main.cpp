#include <iostream>

using namespace std;

void FillArray(int* array, int sizeArray)//функция заполнения массива
{
	for (int i = 0; i < sizeArray; i++)
	{
		*(array + i) = rand() % 100;
	}
}

void ShowArray(int* array, int sizeArray)//функция выведения на экран
{
	cout << "Массив: " << endl;
	for (int i = 0; i < sizeArray; i++)
	{
		cout << *(array + i) << " ";
	}
	cout << endl;
}

void shift(int* array, int N, int start) //функция сдвигает элементы
{
	for (int i = start; i < N - 5; i++)
	{
		int temp = *(array + i + 5);
		*(array + i + 5) = *(array + i);
		*(array + i) = temp;
	}
}
int quadratic_equation(int a, int b, int c, int x = 4)
{																																																																																														
	cout << "Функция Int quadratic equation вызвана!" << endl << "Результат: ";
	return a * x * x + b * x + c;
}

double quadratic_equation(double a, double b, double c, double x)
{
	cout << "Функция Double quadratic equation вызвана!" << endl << "Результат: ";
	return a * x * x + b * x + c;
}
int main(void)
{
	setlocale(LC_ALL, "rus");
	int sizeArray;
	while (true)
	{
		cout << "Введите размерность: ";
		cin >> sizeArray;
		if (sizeArray < 10)
		{
			cout << "Размерность должна быть как минимум 10!" << endl;
		}
		else
		{
			break;
		}
	}
	int* array = new int[sizeArray];
	FillArray(array, sizeArray);
	ShowArray(array, sizeArray);
	int start;
	for (int k = 10; k <= sizeArray; k += 10)
	{
		start = k - 10;
		shift(array, k, start);
	}
	ShowArray(array, sizeArray);
	cout << quadratic_equation(-1, -2, 15, 3) << endl;
	cout << quadratic_equation(-1, -2, 15) << endl;
	cout << quadratic_equation(2.5, 7.5, -1.6, 0.2) << endl;
	return 0;
}
