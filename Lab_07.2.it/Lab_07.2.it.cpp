// Lab_07.2.it.cpp
// Лабораторна робота № 07.2.it
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 1

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void Transpose(int** a, const int n);

int main()
{
    srand((unsigned)time(NULL));

    int n;
    cout << "n = ";
    cin >> n;

    int Low = -10;
    int High = 10;

    // 1. Динамічне виділення пам'яті під двовимірний масив n x n
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    // 2. Формування та виведення початкової матриці
    Create(a, n, Low, High);
    cout << "\nInitial matrix:";
    Print(a, n);

    // 3. Транспонування матриці на місці
    Transpose(a, n);

    // 4. Виведення транспонованої матриці
    cout << "\nTransposed matrix:";
    Print(a, n);

    // 5. Звільнення виділеної пам'яті
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

// Функція формування елементів матриці випадковими числами
void Create(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// Функція виведення матриці на екран у вигляді таблиці
void Print(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(5) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

// Функція транспонування квадратної матриці n x n
void Transpose(int** a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int tmp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = tmp;
        }
    }
}