/*
    Author: Naumov Stanislav

    Group: SBS-001-O-01

    Task: 10
*/

#include <iostream>
#include <cmath>

using namespace std;

int upperBound();

int main()
{
    cout << "|| This program calculates the product. ||";

    const double Pi = 3.14; //Объявляем переменные постоянную переменную Пи
    double res = 1;

    int N = upperBound();

    for (int n = 1; n <= N; n++) { //Вычисляем произведенние с указанной пользователем вверхней границы(N)
        res *= (cos(Pi / (pow(2, (n + 1)))));
    }
    cout << "|| Result product: " << res << endl;
    

    return 0;
}

int upperBound()
{
    while (true) //Цикл работает до тех пор, пока пользователь не введет корректное значение 
    {
        cout << "\n|| Enter the upper limit of the produkt: "; //Запрашиваем данные о верхней границы произведения
        int N;
        cin >> N;

        if (cin.fail() || N < 0) //Если предыдущее извлечение оказалось неудачным и программа ушла в "режим отказа" или N <= 0, то 
        {
            cin.clear(); // возвращаем программу в "нормальный режим"
            cin.ignore(32800, '\n'); // и игнорируем 32 800 значений из входного буфера вплоть до появления символа '\n' (который также удаляем)
        }
        else //Если с вводом все впорядке - возвращаем N
        {
            cin.ignore(32800, '\n'); //Удаляем лишнии значения(если пользователь ввел слишком большое числовое значение)

            return N;
        }
    }
}

