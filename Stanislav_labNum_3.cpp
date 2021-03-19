/*
    Author: Naumov Stanislav

    Group: SBS-001-O-01

    Task: 3.10
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime> 

using namespace std;

double checkInputArr(); //Проверяет введенные пользователем элементы массива ξ(кси)

int sizeArray(); //Запрос на ввод пользователем размера массива

double* arrayXi(int sizeArr); //Заполнение пользователем массива со значениями ξ(кси)

double* probabilityPi(int sizeArr); //Заполнение массива Pi - рандомными значениями от 0.01 до 1 и с их суммой = 1

void helpFunc(); //Раздает размеры массивам

int orderOfTheMoment(); //Запрашивает данные о порядке момента k

int main()
{
   cout << "|| This program calculates the central moment of order ""k"" for a random variable with a given distribution law. ||";

   int size = sizeArray();
   double* Xi;
   double* Pi;
   double Mxi = .0, result = .0, suppVar = .0;

   Xi = (double*)malloc(size * sizeof(double));
   Xi = arrayXi(size);

   Pi = (double*)malloc(size * sizeof(double));
   Pi = probabilityPi(size);

   for (int i = 0; i < size; i++) Mxi += (Xi[i] * Pi[i]);
   cout << "\n|| The mathematical expectation of a random variable MXi: " << Mxi;

   int k = orderOfTheMoment();

   for (int i = 0; i < size; i++)
   {
       for (int j = 0; j < size; j++) suppVar += pow(Xi[i] - Mxi, k) * Pi[j];

       result += suppVar;
   }
   cout << "|| The result of the execution of this program: " << result << endl;

   system("pause");
   return 0;
}

double checkInputArray()
{
    double inputNum;
    while (!(cin >> inputNum))
    {
        cin.clear();
        while (cin.get() != '\n')
        cout << "|| Input ERROR! Place try again: ";
    }
    return inputNum;
}

int sizeArray()
{
    while (true)
    {
        cout << "\n|| Enter the size of the array(not more 30): ";
        int SIZE;
        cin >> SIZE;

        if (cin.fail() || SIZE <= 0 || SIZE > 30)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return SIZE;
        }
    }
}

double* arrayXi(int sizeArr)
{
    double* arrayXi;
    arrayXi = (double*)malloc(sizeArr * sizeof(double));

    for (int numbOfArray = 0; numbOfArray < sizeArr; numbOfArray++) 
    {
        cout << "|| Enter the " << numbOfArray << "-th coefficient of the array(Xi): ";
        arrayXi[numbOfArray] = checkInputArray();
    }
    return arrayXi;
}

double* probabilityPi(int sizeArr)
{
    double* arrPi;
    double sumArrPi = 0;
    arrPi = (double*)malloc(sizeArr * sizeof(double));

    srand(time(NULL));

    for (int i = 0; i < sizeArr; i++)
    {
        arrPi[i] = rand() % 100 / 100. + .01;
        sumArrPi += arrPi[i];
    }

    for (int i = 0; i < sizeArr; i++) arrPi[i] /= sumArrPi;

    sumArrPi = 0;
    cout << "|| The probability of occurrence of each number(Xi), respectively: ";
    for (int i = 0; i < sizeArr; i++) cout <<  arrPi[i] << ' ', sumArrPi += arrPi[i];
    cout << "\n|| Sum of random numbers = " << sumArrPi;

    return arrPi;
}

int orderOfTheMoment()
{
    while (true)
    {
        cout << "\n|| Enter the order of the moment k (integer): ";
        int k;
        cin >> k;

        if (cin.fail() || k < 0) 
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return k;
        }
    }
}

void helpFunc()
{
    int size = sizeArray();
    arrayXi(size);
    probabilityPi(size);
}
