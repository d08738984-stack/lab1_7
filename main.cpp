#include <iostream>
using namespace std;

const int M = 50, N = 50; // максимальна кількість рядків і стовпців матриці

/* ---------- ПРОТОТИПИ ФУНКЦІЙ ---------- */
void task1(); // Matrix20
void task2(); // Matrix57

void get_matr(int matr[M][N], int &m, int &n);
void show_matr(const int matr[M][N], int m, int n);

void col_products(const int matr[M][N], int m, int n);
void swap_quarters(int matr[M][N], int m, int n);

/* ---------- ГОЛОВНА ФУНКЦІЯ ---------- */
int main()
{
    int choice;
    do
    {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1 - Завдання 1 (Matrix20)\n";
        cout << "2 - Завдання 2 (Matrix57)\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice)
        {
            case 1: task1(); break;
            case 2: task2(); break;
            case 0: cout << "Завершення програми...\n"; break;
            default: cout << "Помилка вибору!\n";
        }
    }
    while (choice != 0);

    return 0;
}

/* ---------- ФУНКЦІЯ ВВЕДЕННЯ МАТРИЦІ ---------- */
void get_matr(int matr[M][N], int &m, int &n)
{
    do
    {
        cout << "Введіть кількість рядків (2..50): ";
        cin >> m;
        cout << "Введіть кількість стовпців (2..50): ";
        cin >> n;
    }
    while (m < 2 || m > M || n < 2 || n > N);

    cout << "Введіть елементи матриці:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> matr[i][j];
}

/* ---------- ФУНКЦІЯ ВИВЕДЕННЯ МАТРИЦІ ---------- */
void show_matr(const int matr[M][N], int m, int n)
{
    cout << "\nМатриця:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matr[i][j] << "\t";
        cout << endl;
    }
}

/* ---------- ЗАВДАННЯ 1: Matrix20 ---------- */
/* Для кожного стовпця матриці знайти добуток його елементів */
void col_products(const int matr[M][N], int m, int n)
{
    for (int j = 0; j < n; j++)
    {
        int prod = 1;
        for (int i = 0; i < m; i++)
            prod *= matr[i][j];

        cout << "Добуток елементів стовпця "
             << j + 1 << " = " << prod << endl;
    }
}

/* ---------- ФУНКЦІЯ ВИКОНАННЯ ЗАВДАННЯ 1 ---------- */
void task1()
{
    int matr[M][N];
    int row, col;

    get_matr(matr, row, col);   // введення матриці
    show_matr(matr, row, col);  // виведення матриці

    col_products(matr, row, col); // обчислення добутків стовпців
}

/* ---------- ЗАВДАННЯ 2: Matrix57 ---------- */
/* Поміняти місцями ліву верхню і праву нижню чверті матриці */
void swap_quarters(int matr[M][N], int m, int n)
{
    int halfM = m / 2;
    int halfN = n / 2;

    for (int i = 0; i < halfM; i++)
        for (int j = 0; j < halfN; j++)
        {
            int temp = matr[i][j];
            matr[i][j] = matr[i + halfM][j + halfN];
            matr[i + halfM][j + halfN] = temp;
        }
}

/* ---------- ФУНКЦІЯ ВИКОНАННЯ ЗАВДАННЯ 2 ---------- */
void task2()
{
    int matr[M][N];
    int row, col;

    do
    {
        get_matr(matr, row, col);
        if (row % 2 != 0 || col % 2 != 0)
            cout << "Помилка! Кількість рядків і стовпців має бути парною.\n";
    }
    while (row % 2 != 0 || col % 2 != 0);

    show_matr(matr, row, col); // початкова матриця

    swap_quarters(matr, row, col); // перетворення матриці

    cout << "\nМатриця після перетворення:\n";
    show_matr(matr, row, col); // результат
}
