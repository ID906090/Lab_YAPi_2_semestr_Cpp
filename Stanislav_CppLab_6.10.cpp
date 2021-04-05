#include <iostream>
#include <string>

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

	void show()const 
	{
		auto beg = lHead;
		while (beg != lTail->next) 
		{
			cout << beg->data << ". " << beg->right->data << '\n';
			beg = beg->next;
		}
	}

private:
	NodeDoubleList<Type, Right>* lHead;
	NodeDoubleList<Type, Right>* lTail;
	NodeList<Right>* rHead;
	NodeList<Right>* rTail;
};

int main() 
{
	DoubleList<int, string> dl;

	int key_1 = 1;
	string value_1 = "first";
	dl.add(key_1, value_1);

	int key_2 = 2;
	string value_2 = "second";
	dl.add(key_2, value_2);

	int key_3 = 3;
	string value_3 = "third";
	dl.add(key_3, value_3);

	int key_4 = 4;
	string value_4 = "four";
	dl.add(key_4, value_4);

	int key_5 = 5;
	string value_5 = "five";
	dl.add(key_5, value_5);

	int key_6 = 6;
	string value_6 = "six";
	dl.add(key_6, value_6);

	int key_7 = 7;
	string value_7 = "seven";
	dl.add(key_7, value_7);

	int key_8 = 8;
	string value_8 = "eight";
	dl.add(key_8, value_8);

	dl.show();

	return 0;
}