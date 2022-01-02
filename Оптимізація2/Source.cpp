#include <iostream> 
#include <ctime>
#include <cmath>

using namespace std;


double fact(int number) {
    double factr = 1;
    for (int i = 1; i <= number; i++) {
        factr *= i;
    }
    return factr;
}

double power(float x, int pow) {
    double answer = 1;
    for (int i = 0; i < pow; i++) {

        answer *= x;
    }
    return answer;
}

int main()
{
    setlocale(LC_ALL, "rus");
    double b;
    double sum = 0;
    int k;
    int n = 100;
    float x = -3;
    cout << "X: \t" << "Ñóìà:\t" << "\tÔóíêöiÿ:\n";
    for (int i = 0; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            k = 1;
        }
        else
        {
            k = -1;
        }
        sum += k * (power(x, 2 * i) / fact(2 * i));
        if (i == 100)
        {
            cout << x << "\t" << sum << "\t" << cos(-x) << endl;
            if (x < 2.95)
            {
                i = -1;
                sum = 0;
                x += 0.05;
            }
        }
    }
    return 0;
}
