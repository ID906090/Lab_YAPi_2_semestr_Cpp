#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

int checkInput();

class derivative_Qx {
public:
    int n;
    double* a, x, fluxion = 0, addition = 0;

    void distribute() {
        cout << "|| Введите верхнюю границу массива n: ";
        n = checkInput();

        a = new double[n + 1];

        for (int i = 0; i <= n; i++) {
            cout << "|| a[" << i << "] = ";
            a[i] = checkInput();
        }
    }

    void calc(double x) {
        for (int i = 0; i <= n; i++)
            addition += a[i] * exp(-i * x);
        cout << "|| Qn(x) = " << addition << endl;
    }

    void clearMemory() {
        delete[] a;
    }

    derivative_Qx operator^ (int order) {
        if (addition != 0) {
            double* b = new double[n + 1];

            for (int i = 0; i <= n; i++)
                b[i] = a[i] * (-1) * i;

            for (int j = 1; j <= order; j++) {
                for (int i = 0; i <= n; i++) {
                    fluxion += b[i] * exp(-i * x);
                    b[i] *= -i;
                }
                cout << "|| Производная " << j << " порядка, значение производной: " << fluxion << endl;
            }
            delete[] b;
        }
        return *this;
    }
};

int enterX();

int main() 
{
    setlocale(LC_ALL, "Ru");

    cout << "|| Данная программа вычисляет производную произвольного порядка Qn(x) ||" << endl;

    derivative_Qx obj;
    obj.distribute();

    cout << "|| Введите аргумент x:  ";
    double x = enterX();
    obj.calc(x);

    cout << "|| Введите порядок производной: ";
    int exponent = checkInput();
    obj ^ exponent;

    obj.clearMemory();
    return 0;
}

int checkInput() 
{
    while (true)
    {
        int num;
        cin >> num;

        if (cin.fail() || num < 1)
        {
            cout << "|| Ошибка: введено недопустимое значение.\n|| Повторите ввод: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return num;
        }
    }
}

int enterX()
{
    while (true)
    {
        int num;
        cin >> num;

        if (cin.fail())
        {
            cout << "|| Ошибка: введено недопустимое значение.\n|| Повторите ввод: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return num;
        }
    }
}