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
    double sum;
    int k;
    int n;
    double temp = 0;
    double m;
    cout << "Ââåäiòü òî÷íiñòü:\n";
    cin >> m;
    cout << "X: \tÑóìà:\t\tÔóíêöiÿ:\tÊië. iòåðàöié:\n";
    for (float x = -3; x <= 3; x += 0.05)
    {
        sum = 0;
        n = 0;
        do {
            temp = sum;
            if (n % 2 == 0)
            {
                k = 1;
            }
            else
            {
                k = -1;
            }
            sum += k * (power(x, 2 * n) / fact(2 * n));
            n++;
        } while (abs(abs(sum) - abs(temp)) > m);
        cout << x << "\t" << sum << "\t" << cos(-x) << "\t" << n << endl;
    }
    return 0;
}
