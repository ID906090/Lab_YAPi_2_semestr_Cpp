#include <iostream> 

using namespace std;

template <class Type>
class Array {
private:
	unsigned int m_row;		//храним количество строк 
	unsigned int m_col;		//храним количество столбцов 
	Type** arr;				//переменная в которой хранится указатель на массив 
	Array() {}

public:
	Array(const unsigned int row, const unsigned int col) : m_row(row), m_col(col) // Конструктор который выделяет память для массива 
	{
		arr = new Type * [m_row]; 
		for (unsigned i = 0; i < m_row; i++) arr[i] = new Type[m_col];
	}

	unsigned row() const { return m_row; }	// Возращаем количество строк и столбцов
	unsigned col() const { return m_col; }

	~Array()
	{
		for (int i = 0; i < m_row; i++) delete[]arr[i];
		delete[]arr;
	}

	Type* operator[](const int i) // Перегружаем оператор [] 
	{
		return arr[i];
	}
};

int main() 
{
	Array<int> intArray(5, 5);
	unsigned int count = 0;	

	for (unsigned int i = 0; i < intArray.row(); i++) {
		for (unsigned int j = 0; j < intArray.col(); j++) {
			intArray[i][j] = count++;
		}
	}

	for (unsigned int i = 0; i < intArray.row(); i++) {
		for (unsigned int j = 0; j < intArray.col(); j++) {
			cout << intArray[i][j] << '\t';
		}
		cout << endl;
	}

	return 0;
};
