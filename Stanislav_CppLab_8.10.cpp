#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

class ComlexSine
{
public:
    double Re;
    double Im;
    double Modul;
    double Arg;

    void ConvertToAlgebraicForm(ComlexSine& number)
    {
        number.Re = number.Modul * cos(number.Arg);
        number.Im = number.Modul * sin(number.Arg);
    }

    void CalculateComplexSin(const ComlexSine& number)
    {
        ComlexSine sine{};
        sine.Re = sin(number.Re) * cosh(number.Im);
        sine.Im = cos(number.Re) * sinh(number.Im);
        sine.Modul = hypot(sine.Re, sine.Im);
        sine.Arg = acos(sine.Re / sine.Modul);

        // Установка формата вывода числовых данных
        cout << "|| sin(z) = "
             << setiosflags(ios::fixed | ios::showpos)
             << sine.Re << ' ' << sine.Im << "i\n";
    }
};

double	GetRealNumber(); // Проверка на ввод чисел
double	GetPositiveRealNumber(); // Проверка на ввод модуля z (в триг форме)
char	GetComplexRepresentationType(); // Выбор пользователем формы представления вводимого им комплексного числа
void	GetComplexNumber(ComlexSine&); // Выбор пользователя, ввод комплексного числа в алгебр или триг форме

int main()
{
    setlocale(LC_ALL, "RUS");

    cout << "|| Данная программа вычисляет синус от комплексного аргумента. ||\n";

    ComlexSine numberZ{}, add;
    GetComplexNumber(numberZ);

    add.CalculateComplexSin(numberZ);

    return 0;
}

char GetComplexRepresentationType()
{
    char userChoice{};

    do {
        cout << "\n|| Выбирите форму представления комплексного числа z:"
            << "\n|| а - алгебраическая   t - тригонометрическая"
            << "\n|| Ваш выбор: ";
        cin >> setw(1) >> userChoice; // Пропускаем все введённые символы, кроме первого
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (userChoice != 'a' && userChoice != 't') {
            cout << "\n|| Вы ввели недопустимое значение";
        }
    } while (userChoice != 'a' && userChoice != 't');

    return userChoice;
}

void GetComplexNumber(ComlexSine& number)
{
    const char algebraic = 'a';
    const char trigonometric = 't';
    const char complexRepresentation = GetComplexRepresentationType();

    if (complexRepresentation == algebraic) {
        cout << "|| Введите Re(z): ";
        number.Re = GetRealNumber();
        cout << "|| Введите Im(z): ";
        number.Im = GetRealNumber();
    }
    else if (complexRepresentation == trigonometric) {
        cout << "|| Введите |z|: ";
        number.Modul = GetPositiveRealNumber();
        cout << "|| Введите Arg(z): ";
        number.Arg = GetRealNumber();

        number.ConvertToAlgebraicForm(number);
    }
}

double GetRealNumber()
{
    bool isReal{};
    double num{};

    do {
        cin >> num;
        isReal = cin.good();

        if (!isReal) {
            cout << "|| Ошибка: введено недопустимое значение\nПовторите ввод: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!isReal);

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return num;
}

double GetPositiveRealNumber()
{
    bool isPositive{};
    double num{};

    do {
        num = GetRealNumber();
        isPositive = (num < 0.0 ? false : true);

        if (!isPositive) {
            cout << "|| Ошибка: введено отрицательное значение\nПовторите ввод: ";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!isPositive);

    //cin.clear() не нужен, т. к. отрицательное число соответсвует типу double 

    return num;
}