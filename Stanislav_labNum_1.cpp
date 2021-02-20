/*
    Author: Naumov Stanislav

    Group: SBS-001-O-01

    Task: 10
*/

#include <iostream>
#include <cmath>

using namespace std;

double height();

int main()
{
    cout << "|| This program calculates the acceleration of gravity of a body relative to the earth's surface. ||";

    //Объявляем значения - константы(Гравит. постоянная, Масса земли, радиус земли соответственно)
    const double G = (6.672 * pow(10, -11));
    const double M = (5.96 * pow(10, 24));
    const double R = (6.37 * pow(10, 6));
    
    double H = height();
    
    double g = (G * ( M / (pow((R + H), 2))));
   
    cout << "\n|| Free fall acceleration of a given body = " << g ;
   
    return 0;
}

double height()
{
    while (true) //Цикл работает до тех пор, пока пользователь не введет корректное значение 
    {
        cout << "\n|| Enter the distance from the ground (in meters): "; //Запрашиваем данные о высоте над поверхностью земли
        double H;
        cin >> H;

        if (cin.fail() || H <= 0) //Если предыдущее извлечение оказалось неудачным и программа ушла в "режим отказа" или H <= 0, то 
        {
            cin.clear(); // возвращаем программу в "нормальный режим"
            cin.ignore(32800, '\n'); // и игнорируем 32 800 значений из входного буфера вплоть до появления символа '\n' (который также удаляем)
        }
        else //Если с вводом все впорядке - возвращаем H
            return H;
    }
}
