#include <iostream> 

using namespace std;

int main(void)
{
	int number;
	cout << "Enter the number: ";
	cin >> number;
	int sum = 0;
	int multi = 1;
	int* pArray;
	while (number != 0)
	{
		sum += number % 10;
		multi *= number % 10;
		number /= 10;
	}
	cout << "Summ: " << sum << endl;
	cout << "Multiplication: " << multi << endl;
	return 0;
}
