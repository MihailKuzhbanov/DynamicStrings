#include <iostream>
#include <string>

using namespace std;

class DynStr
{
public:
	int size;				//количество строк
	string* Container;		//указатель на контейнер
	
	//конструктор
	DynStr(int size)
	{
		this->size = size;
		Container = new string[size];
		cout << "Creating constructor" << endl;
	}

	//деструктор
	~DynStr()
	{
		cout << "Destructor" << endl;
	}

	//конструктор копирования
	DynStr(const DynStr &obj)
	{
		cout << "Copy constructor" << endl;
	}

	//перегрузка оператора присваивания
	DynStr& operator=(const DynStr &obj)
	{
		return *this;
		cout << "Operator overload" << endl;
	}

	//добавление строки в конец
	void AddStr(string newStr)
	{
		size++;
		string* newContainer = new string[size];
		for (int i = 0; i < size-1; i++)
		{
			newContainer[i] = Container[i];
		}
		newContainer[size-1] = newStr;
		Container = newContainer;
		cout << "String added" << endl;
	}


};

int main()
{
	DynStr* a = new DynStr(5);
	cout << a->size << endl;
	a->AddStr("smth");
	//DynStr* b = DynStr(a);
	DynStr* c = a;
	b->AddStr("noth");
	cout << "a size: " << a->size << endl;
	cout << "b size: " << b->size << endl;
	cout << "c size: " << c->size << endl;
	cout << b->Container[6]<<endl;
	system("pause");
	return 0;
}