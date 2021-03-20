#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const size_t SIZE{ 3 };

int checkInputArray(); //Проверка на корректность ввода векторов

void vectors(); //Ввод векторов 

void calculatingThePhiAngle(int A[SIZE], int B[SIZE]); //Расчет по формуле

int main()
{
    cout << "|| This program calculates the angle (in degrees) between two vectors according to the ratio: a * b = | a | * | b | * cos (Phi). ||\n";

    vectors();

    system("pause");
    return 0;
}

int checkInputArray()
{
    while (true)
    {
        int numArr;
        cin >> numArr;

        if (cin.fail() || numArr == 0 )
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return numArr;
        }
    }
}

void vectors()
{
    int vectorA[SIZE];
    int vectorB[SIZE];

    for (int i = 0; i < SIZE; i++) cout << "|| Enter the " << i + 1 << "-th  value of vector A: ", vectorA[i] = checkInputArray();

    for (int i = 0; i < SIZE; i++) cout << "|| Enter the " << i + 1 << "-th  value of vector B: ", vectorB[i] = checkInputArray();

    calculatingThePhiAngle(vectorA, vectorB);
}

void calculatingThePhiAngle(int A[SIZE], int B[SIZE])
{
    double phi;
    int numerator = 0, denominator = 0;

    for (int i = 0; i < SIZE; i++) numerator += A[i] * B[i];

    for (int j = 0; j < SIZE; j++) denominator += (abs(A[j])) * (abs(B[j]));

    phi = ((acos(numerator / denominator) * 180) / 3.14);

    cout << "|| The result of the program execution (in degrees): " << phi << endl;
}