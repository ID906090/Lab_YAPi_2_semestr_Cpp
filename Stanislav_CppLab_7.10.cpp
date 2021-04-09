#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

template<typename Type>
class QuadEquat
{
private:
	Type x1;
	Type x2;
	Type d;

public:
	void Сalculation(Type a, Type b, Type c)
	{
		d = (b * b) - (4 * a * c);

		if (d == 0) // Если дискриминант = 0, будет 1 корень
		{
			x1 = (-b + sqrt(d)) / (2 * a);
			cout << "|| Ответ: x = " << x1 << endl;
		}

		if (d > 0) // Если дискриминант > 0, будет 2 корня
		{
			x1 = (-b + sqrt(d)) / (2 * a);
			x2 = (-b - sqrt(d)) / (2 * a);
			cout << "|| Ответ: x1 = " << x1 << ", x2 = " << x2 << endl;
		}

		if (d < 0) // Если дискриминант меньше нуля - комплексное число, корней нет
		{
			cout << "|| Ответ: Корней нет. " << endl;
		}
	}
};

double CheckInput(); // Проверка на корректность пльзовательского ввода 

void Enter(); // Запрашивает данные у пользователя

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "|| Данная программа вычисляет корни квадратного уравнения вида: ||"
		 << "\n|| Ax^2 + Bx + C = 0                                            ||" << endl;
	
	Enter();

	return 0;
}

double CheckInput()
{
	while (true)
	{
		double num;
		cin >> num;

		if (cin.fail())
		{
			cout << "\n|| ERROR! Повторите попытку еще раз: ";
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

void Enter()
{
	double A, B, C;

	cout << "|| Введите значение А: ";
	A = CheckInput();

	cout << "|| Введите значение B: ";
	B = CheckInput();

	cout << "|| Введите значение C: ";
	C = CheckInput();

	QuadEquat<double> inp;
	inp.Сalculation(A, B, C);
}