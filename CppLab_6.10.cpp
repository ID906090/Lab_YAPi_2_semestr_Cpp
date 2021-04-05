#include <iostream>
#include <string>

using namespace std;

template<typename Right>
struct NodeList {
	Right data;
	NodeList* next;
	NodeList() : next(nullptr) {}
};

template<typename Type, typename Right>
struct NodeDoubleList {
	Type data;
	NodeDoubleList* next;
	NodeList<Right>* right;
	NodeDoubleList() : next(nullptr), right(nullptr) {}
};

template<typename Type, typename Right>
class DoubleList {
public:
	DoubleList() : lhead(nullptr), ltail(nullptr), rhead(nullptr), rtail(nullptr) {}
	void add(const Type& ldata, const Right& rdata) {
		auto lptr = new NodeDoubleList<Type, Right>;
		lptr->data = ldata;
		auto rptr = new NodeList<Right>;
		rptr->data = rdata;
		if (!lhead) 
		{
			rhead = rptr;
			rtail = rhead;
			lhead = lptr;
			ltail = lhead;
		}
		else 
		{
			rtail->next = rptr;
			ltail->next = lptr;
			rtail = rtail->next;
			ltail = ltail->next;

		}

		rtail->next = nullptr;
		ltail->next = nullptr;
		ltail->right = rtail;
	}

	void show()const 
	{
		auto beg = lhead;
		while (beg != ltail->next) {
			cout << beg->data << ". " << beg->right->data << '\n';
			beg = beg->next;
		}
	}

private:
	NodeDoubleList<Type, Right>* lhead;
	NodeDoubleList<Type, Right>* ltail;
	NodeList<Right>* rhead;
	NodeList<Right>* rtail;
};

int main() {
	DoubleList<int, string> dl;

	int key1 = 1;
	string value1 = "first";
	dl.add(key1, value1);

	int key2 = 2;
	string value2 = "second";
	dl.add(key2, value2);

	int key3 = 3;
	string value3 = "third";
	dl.add(key3, value3);

	int key4 = 4;
	string value4 = "four";
	dl.add(key4, value4);

	int key5 = 5;
	string value5 = "five";
	dl.add(key5, value5);

	int key6 = 6;
	string value6 = "six";
	dl.add(key6, value6);

	int key7 = 7;
	string value7 = "seven";
	dl.add(key7, value7);

	int key8 = 8;
	string value8 = "eight";
	dl.add(key8, value8);

	dl.show();

	system("pause");
	return 0;
}