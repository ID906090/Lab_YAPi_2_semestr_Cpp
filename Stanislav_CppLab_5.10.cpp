#include <iostream>
#include <cmath>
#include <limits>
#include <clocale>

using namespace std;

int checkInputArray(); //Проверка на корректность ввода матриц

int sizeArray(); //Ввод и проверка на корректность ввода размера матриц

int** enterMatrices(int sizeArr); //Ввод матриц

void matrixSubtraction(int sizeArr); //Операция "вычитание" над матрицами

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "|| Данная программа производит вычитание квадратных матриц(В из А). ||";
    
    int size = sizeArray();

    matrixSubtraction(size);

    system("pause");
    return 0;
}

int checkInputArray()
{
    while (true)
    {
        int numArr;
        cin >> numArr;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return numArr;
        }
    }
}

int sizeArray()
{
    while (true)
    {
        cout << "\n|| Введите размер квадратных матриц(n x n): ";
        int SIZE;
        cin >> SIZE;

        if (cin.fail() || SIZE <= 0 )
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return SIZE;
        }
    }
}

int** enterMatrices(int sizeArr) //Матрицы размером i, j --> matrix[i][j], где i - строка, j - столбец
{
    int** matrix;
    
    matrix = new int* [sizeArr];
    for (int i = 0; i < sizeArr; i++) matrix[i] = new int[sizeArr];

    for (int i = 0; i < sizeArr; i++)
    {
        for (int j = 0; j < sizeArr; j++)
        {
            cout << "|| Введите " << i + 1 << "." << j + 1 << " элемент матрицы: ";
            matrix[i][j] = checkInputArray();
        }
    }

    return matrix;
}

void matrixSubtraction(int sizeArr)
{
    int** matrixA;
    int** matrixB;
    int** matrixRes;

    cout << "\n|| Введите элементы первой матрицы(А): \n";
    matrixA = new int* [sizeArr];
    for (int i = 0; i < sizeArr; i++) matrixA[i] = new int[sizeArr];

    matrixA = enterMatrices(sizeArr);

    cout << "\n|| Введите элементы второй матрицы(В): \n";
    matrixB = new int* [sizeArr];
    for (int i = 0; i < sizeArr; i++) matrixB[i] = new int[sizeArr];

    matrixB = enterMatrices(sizeArr);

    matrixRes = new int* [sizeArr];
    for (int i = 0; i < sizeArr; i++) matrixRes[i] = new int[sizeArr];

    for (int i = 0; i < sizeArr; i++) 
    {
        for (int j = 0; j < sizeArr; j++) 
        {
            matrixRes[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }

    cout << "|| Первая матрица(А): \n";
    for (int i = 0; i < sizeArr; i++) {
        for (int j = 0; j < sizeArr; j++) {
            cout << matrixA[i][j] << " ";
        }
        cout << endl;
    }

    cout << "|| Вторая матрица(В): \n";
    for (int i = 0; i < sizeArr; i++) {
        for (int j = 0; j < sizeArr; j++) {
            cout << matrixB[i][j] << " ";
        }
        cout << endl;
    }

    cout << "|| Разность матриц(А - В): \n";
    for (int i = 0; i < sizeArr; i++) {
        for (int j = 0; j < sizeArr; j++) {
            cout << matrixRes[i][j] << "  ";
        }
        cout << endl;
    }

    for (int value = 0; value < sizeArr; value++) delete[]matrixA[value];
    delete[]matrixA;

    for (int value = 0; value < sizeArr; value++) delete[]matrixB[value];
    delete[]matrixB;

    for (int value = 0; value < sizeArr; value++) delete[]matrixRes[value];
    delete[]matrixRes;
}
