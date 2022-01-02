#include <iostream> 
#include <ctime>

using namespace std;

int main(void)
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int a;
    int tmp0, tmp1, tmp2, tmp3, tmp4;
    cout << "¬ведте размерность матрицы:";
    cin >> a;
    int* array = new int[a];
    for (int i = 0; i < a; i++)
    {
        array[i] = rand() % 100;
        cout << array[i] << " ";
    }
    for (int i = 0; i < a; i++)
    {
        for (int n = 0; n < 5; n++)
        {
                if (array[i] == array[n])
                {
                    tmp0 = array[n];
                    array[n] = array[5 + n];
                    array[5 + n] = tmp0;
                }
            
        }
    }
    cout << endl;
    for (int i = 0; i < a; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}
/*#include <iostream>
#include <ctime>

using namespace std;

int main(void)
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int a;
    int tmp0, tmp1, tmp2, tmp3, tmp4;
    cout << "¬ведте размерность матрицы:";
    cin >> a;
    int *array = new int[a];
    for (int i = 0; i < a; i++)
    {
        array[i] = rand() % 100;
        cout << array[i] << " ";
    }
    for (int i = 0; i < a; i++)
    {

            if (array[i] == array[0])
            {
                tmp0 = array[0];
                array[0] = array[5];
                array[5] = tmp0;
            }
            if (array[i] == array[1])
            {
                tmp1 = array[1];
                array[1] = array[6];
                array[6] = tmp1;
            }
            if (array[i] == array[2])
            {
                tmp2 = array[2];
                array[2] = array[7];
                array[7] = tmp2;
            }
            if (array[i] == array[3])
            {
                tmp3 = array[3];
                array[3] = array[8];
                array[8] = tmp3;
            }
            if (array[i] == array[4])
            {
                tmp4 = array[4];
                array[4] = array[9];
                array[9] = tmp4;
            }

    }
    cout << endl;
    for (int i = 0; i < a; i++)
    {
        cout << array[i] << " ";
    }
}*/
/*
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define n 5
#define m 6
int main()
{
    int matr[n][m];
    int i, j, tmp, l, k;
    srand(time(NULL));
    printf("Ishodnaya matrica:\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            matr[i][j] = rand() % 100;
            printf(" %2i", matr[i][j]);
        }
        printf("\n\n");
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (matr[i][j] == matr[i][2]) l = j;
            if (matr[i][j] == matr[i][4]) k = j;
        }
        tmp = matr[i][l];
        matr[i][l] = matr[i][k];
        matr[i][k] = tmp;
    }
    printf("Izmenennaya matrica:\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf(" %2i", matr[i][j]);
        }
        printf("\n\n");
    }
    system("pause");
}*/