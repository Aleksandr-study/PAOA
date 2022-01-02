#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand((int)time(0));
    const int n = 6;
    int D[n][n], A, B, pos = 0, neg = 0;
    long long mult_neg = 1, mult_pos = 1;

    cout << "Enter A,B:\n";
    cin >> A >> B;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            D[i][j] = rand() % (B - A + 1) + A;
            cout << D[i][j] << " ";
        }
        if (D[i][n - i - 1] < 0) { neg = 1; mult_neg *= D[i][n - i - 1]; }
        else if (D[i][n - i - 1] > 0) { pos = 1; mult_pos *= D[i][n - i - 1]; }
        cout << "\n";
    }

    cout << "Second diagonal:\n";

    if (neg) cout << "mult negative = " << mult_neg << "\n";
    else cout << "Negative elements are absent\n";

    if (pos) cout << "mult positive = " << mult_pos << "\n";
    else cout << "Positive elements are absent\n";

    system("pause");
    return 0;
}