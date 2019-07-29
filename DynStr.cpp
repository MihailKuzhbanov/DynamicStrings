#include <iostream>
#include <string>

using namespace std;

class DynStr
{
public:
	int size;				//���������� �����
	string* Container;		//��������� �� ���������
	
	//�����������
	DynStr(int size)
	{
		this->size = size;
		Container = new string[size];
	}

	//����������
	~DynStr()
	{
		
	}

	//����������� �����������
	DynStr(const DynStr &obj)
	{
		*this = obj;
	}

	//���������� ��������� ������������
	DynStr& operator=(const DynStr &obj)
	{

		return *this;
	}

	//���������� ������ � �����
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


};

int main()
{
	DynStr* a = new DynStr(5);
	cout << a->size << endl;
	a->AddStr("smth");
	DynStr* b = new DynStr(*a);
	DynStr* c = a;
	b->AddStr("noth");
	cout << "a size: " << a->size << endl;
	cout << "b size: " << b->size << endl;
	cout << "c size: " << c->size << endl;
	cout << b->Container[6]<<endl;
	system("pause");
	return 0;
}