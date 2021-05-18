#include <iostream>
#include <string>
#include <limits>
#include <clocale>

using namespace std;

template<typename Right>
struct NodeList
{
	Right data;
	NodeList* next;
	NodeList() : next(nullptr) {}
};

template<typename Type, typename Right>
struct NodeDoubleList
{
	Type data;
	NodeDoubleList* next;
	NodeList<Right>* right;
	NodeDoubleList() : next(nullptr), right(nullptr) {}
};

template<typename Type, typename Right>
class DoubleList
{
public:
	DoubleList() : lHead(nullptr), lTail(nullptr), rHead(nullptr), rTail(nullptr) {}

	void add(const Type& lData, const Right& rData)
	{
		auto lPtr = new NodeDoubleList<Type, Right>;
		lPtr->data = lData;
		auto rPtr = new NodeList<Right>;
		rPtr->data = rData;
		if (!lHead)
		{
			rHead = rPtr;
			rTail = rHead;
			lHead = lPtr;
			lTail = lHead;
		}
		else
		{
			rTail->next = rPtr;
			lTail->next = lPtr;
			rTail = rTail->next;
			lTail = lTail->next;

		}

		rTail->next = nullptr;
		lTail->next = nullptr;
		lTail->right = rTail;
	}

	void show()const // Выводит результат в консоль
	{
		auto beg = lHead;
		while (beg != lTail->next)
		{
			cout << "|| " << beg->data << ". " << beg->right->data << '\n';
			beg = beg->next;
		}
	}

private:
	NodeDoubleList<Type, Right>* lHead;
	NodeDoubleList<Type, Right>* lTail;
	NodeList<Right>* rHead;
	NodeList<Right>* rTail;
};

int SizeList(); // Проверка ввода на корректность количества элементов в списке

int InputLeft(); // Проверка на ввод левых элементов списка

string InputRight(); // Проверка на ввод правых элементов списка

void PrintFunc(); // Заполнение списка и вывод его в консоль

int main()
{
	setlocale(LC_ALL, "RU");

	cout << "|| Данная программа запрашивает данные для двойного списка с односторонней связью, ||"
		<< "\n|| запоняет его и выводит результат на экран.                                     ||"
		<< "\n|| Примечание: Элементы списка слева - целочисленные. Справа - любого типа.       ||" << endl;

	PrintFunc();

	return 0;
}

int SizeList()
{
	while (true)
	{
		cout << "\n|| Введите количество элементов в списке(Не больше 25): ";
		int SIZE;
		cin >> SIZE;

		if (cin.fail() || SIZE <= 0 || SIZE > 25)
		{
			cout << "|| Ошибка: введено недопустимое значение.\n|| Повторите ввод: ";
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

int InputLeft()
{
	while (true)
	{
		int num;
		cout << "\n|| Введите значение левого элемента списка(только целочисленные числа): ";
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

string InputRight()
{
	cout << "|| Введите значение правого элемента списка: ";
	string value;
	getline(cin, value);

	return value;
}

void PrintFunc()
{
	int SIZE = SizeList();

	DoubleList<int, string> dl;

	for (int i = 0; i < SIZE; i++)
	{
		int key = InputLeft();

		string value = InputRight();

		dl.add(key, value);
	}

	cout << "\n|| Результат выполнения данной программы: " << endl;
	dl.show();
}
