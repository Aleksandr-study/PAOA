#include <iostream> 

using namespace std;

int main(void)
{
	float number, pow;
	cout << "Enter the number and power: ";
	cin >> number >> pow;
	float result = 1;
	if (pow > 0)
	{
		for (int i = 0; i < pow; i++)
		{
			result *= number;

		}
		cout << "Result: " << result;
	}
	else
	{
		for (int i = 0; i < -pow; i++)
		{
			result *= 1/number;
		}
		cout << "Result: " << result;
	}
}