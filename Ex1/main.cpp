#include <iostream>
using namespace std;
int main()
{
	int digit, count;
	long int factor;
	cout << "Enter the number";
	cin >> digit;
	factor = 1;
	for (count = 1; count <= digit; count++)
	{
		factor *= count;
	}
	cout << "Factorial of " << digit << " is " << factor;
	return 0;
}