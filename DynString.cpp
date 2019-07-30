#include "DynString.h"


	//constructor empty array
	DynString::DynString(int size)
	{
		this->size = size;
		Container = new string[size];
	}

	//constructor filled array
	DynString::DynString(string* str, int size)
	{
		this->size = size;
		Container = new string[size];
		for (int i = 0; i < size; i++)
		{
			Container[i] = str[i];
		}
	}

	//destructor
	DynString::~DynString()
	{

	}

	//copy constructor
	DynString::DynString(const DynString &obj)
	{
		size = obj.size;
		Container = new string[size];
		for (int i = 0; i < size; i++)
		{
			Container[i] = obj.Container[i];
		}
	}

	//move constructor
	DynString::DynString(DynString &&obj)
	{
		size = obj.size;
		Container = obj.Container;
		obj.size = 0;
		obj.Container = nullptr;
	}

	//assignment operator overload
	DynString& DynString::operator=(const DynString &obj)
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

	//move assignment operator overload
	DynString& DynString::operator=(DynString&& obj)
	{
		if (this != &obj)
		{
			delete[] Container;

			Container = obj.Container;
			size = obj.size;

			obj.Container = nullptr;
			obj.size = 0;
		}
		return *this;
	}


	//add element in the end
	void DynString::AddStr(string newStr)
	{
		size++;
		string* newContainer = new string[size];
		for (int i = 0; i < size - 1; i++)
		{
			newContainer[i] = Container[i];
		}
		newContainer[size - 1] = newStr;
		Container = newContainer;
	}

	//add element by index
	void DynString::AddStr(string newStr, int index)
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
	void DynString::DelStr(int index)
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
		for (int i = index; i < size - 1; i++)
		{
			newContainer[i] = Container[i + 1];
		}
		Container = newContainer;
	}

	//delete element by value
	void DynString::DelStr(string delStr)
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

	//output content
	void DynString::Show()
	{
		for (int i = 0; i < size; i++)
		{
			cout << Container[i] << " ";
		}
		cout << endl;
	}

	//sorting content
	void DynString::Sort()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (strcmp(Container[i].c_str(), Container[j].c_str()) > 0) swap(Container[i], Container[j]);
			}
		}
	}


