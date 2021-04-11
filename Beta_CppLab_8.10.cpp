#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

struct Complex 
{
    double Re;
    double Im;
    double Modul;
    double Arg;
};

class SinComplexSine
{


    void ConvertToAlgebraicForm(Complex& number)
    {
        number.Re = number.Modul * cos(number.Arg);
        number.Im = number.Modul * sin(number.Arg);
    }

    void CalculateComplexSin(const Complex& number)
    {
        Complex sine{};
        sine.Re = sin(number.Re) * cosh(number.Im);
        sine.Im = cos(number.Re) * sinh(number.Im);
        sine.Modul = hypot(sine.Re, sine.Im);
        sine.Arg = acos(sine.Re / sine.Modul);

        PrintComplexNumber(sine);
    }

    void PrintComplexNumber(const Complex& sinus)
    {
        cout << "\nsin(z) = ";
        //установка формата вывода числовых данных
        cout << setiosflags(ios::fixed | ios::showpos)
             << sinus.Re << ' ' << sinus.Im << "i\n";
    }
};

double	GetRealNumber();
double	GetPositiveRealNumber();
char	GetComplexRepresentationType();
void	GetComplexNumber(Complex&);

int main()
{
    setlocale(LC_ALL, "RUS");

    Complex numberZ{};
    GetComplexNumber(numberZ);

    SinComplexSine CalculateComplexSin(Complex& numberZ);
    SinComplexSine PrintComplexNumber();

    return 0;
}

char GetComplexRepresentationType()
{
    //выбор пользователем формы представления
    //вводимого им комплексного числа
    char userChoice{};

    do {
        cout << "\nВыбирите форму представления комплексного числа z:"
             << "\nа - алгебраическая\nt - тригонометрическая"
             << "\nВаш выбор: ";
        cin >> setw(1) >> userChoice;
        //пропускаем все введённые символы, кроме первого
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (userChoice != 'a' && userChoice != 't') {
            cout << "\nВы ввели недопустимое значение";
        }
    } while (userChoice != 'a' && userChoice != 't');

    return userChoice;
}

void GetComplexNumber(Complex& number)
{
    const char algebraic = 'a';
    const char trigonometric = 't';
    const char complexRepresentation = GetComplexRepresentationType();

    if (complexRepresentation == algebraic) {
        cout << "Введите Re(z): ";
        number.Re = GetRealNumber();
        cout << "Введите Im(z): ";
        number.Im = GetRealNumber();
    }
    else if (complexRepresentation == trigonometric) {
        cout << "Введите |z|: ";
        number.Modul = GetPositiveRealNumber();
        cout << "Введите Arg(z): ";
        number.Arg = GetRealNumber();
            
        SinComplexSine ConvertToAlgebraicForm(number);
    }
}

double GetRealNumber()
{
    bool isReal{};
    double scanedNumber{};

    //ввод с проверкой
    do {
        cin >> scanedNumber;
        isReal = cin.good();

        if (!isReal) {
            cout << "Ошибка: введено недопустимое значение\nПовторите ввод: ";
            //очистка потока
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!isReal);

    //финальная очистка потока
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return scanedNumber;
}

double GetPositiveRealNumber()
{
    bool isPositive{};
    double scanedNumber{};

    //ввод с проверкой
    do {
        scanedNumber = GetRealNumber();
        isPositive = (scanedNumber < 0.0 ? false : true);

        if (!isPositive) {
            cout << "Ошибка: введено отрицательное значение\nПовторите ввод: ";
            //очистка потока
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!isPositive);

    //cin.clear() не нужен, т. к. отрицательное число соответсвует типу double 

    return scanedNumber;
}