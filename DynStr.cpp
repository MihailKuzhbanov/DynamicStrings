#include <iostream>
#include <string>

using namespace std;

class DynStr
{
	
public:
	int size;				//strings amount
	string* Container;		//pointer
	
	//constructor
	DynStr(int size)
	{
		this->size = size;
		Container = new string[size];
	}

	//destructor
	~DynStr()
	{
		
	}

	//copy constructor
	DynStr(const DynStr &obj)
	{
		size = obj.size;
		Container = new string[size];
		for (int i = 0; i < size; i++)
		{
			Container[i] = obj.Container[i];
		}
	}

	//assignment operator overload
	DynStr& operator=(const DynStr &obj)
	{
		if (this != &obj)
		{
			delete[] Container;
			size = obj.size;
			Container = new string[size];
			for (int i = 0; i < size; i++)
			{
				Container[i] = obj.Container[i];
			}
		}
		else cout << "Self-assignment";

		return *this;
	}

	//add element in the end
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
	}

	//add element by index
	void AddStr(string newStr, int index)
	{
		if (index >= size)
		{
			cout << "Wrong index" << endl;
			return;
		}
		size++;
		string* newContainer = new string[size];
		for (int i = 0; i < index; i++)
		{
			newContainer[i] = Container[i];
		}
		newContainer[index] = newStr;
		for (int i = index + 1; i < size - 1; i++)
		{
			newContainer[i] = Container[i - 1];
		}
		Container = newContainer;
	}

	
	//delete element by index
	void DelStr(int index)
	{
		if (index >= size)
		{
			cout << "Wrong index" << endl;
			return;
		}
		size--;
		string* newContainer = new string[size];
		for (int i = 0; i < index; i++)
		{
			newContainer[i] = Container[i];
		}
		for (int i = index; i < size-1; i++)
		{
			newContainer[i] = Container[i+1];
		}
		Container = newContainer;
	}

	//delete element by value
	void DelStr(string delStr)
	{
		int index;
		bool found = false;
		for (int i = 0; i < size; i++)
		{
			if (Container[i] == delStr)
			{
				index = i;
				found = true;
			}
		}
		if (!found)
		{
			cout << "Element not found" << endl;
			return;
		}
		size--;
		string* newContainer = new string[size];
		for (int i = 0; i < index; i++)
		{
			newContainer[i] = Container[i];
		}
		for (int i = index; i < size - 1; i++)
		{
			newContainer[i] = Container[i + 1];
		}
		Container = newContainer;
	}


};

int main()
{

	DynStr* a = new DynStr(5);
	cout << a->size << endl;
	a->AddStr("smth");
	DynStr* b = new DynStr(*a);
	DynStr* c = a;
	b->AddStr("noth");
	c->AddStr("allt");
	cout << "a size: " << a->size << endl;
	cout << "b size: " << b->size << endl;
	cout << "c size: " << c->size << endl;
	cout << "same position elements:" << endl;
	cout << "a: " << a->Container[6] << endl;
	cout << "b: " << b->Container[6] << endl;
	cout << "c: " << c->Container[6] << endl;

	a->DelStr("smth");
	cout << "a size: " << a->size << endl;
	a->DelStr(6);
	cout << "a size: " << a->size << endl;
	a->DelStr(5);
	cout << "a size: " << a->size << endl;

	cout << "third element: " << a->Container[3] << endl;
	a->AddStr("empty", 3);
	cout << "third element: " << a->Container[3] << endl;


	system("pause");
	return 0;
}