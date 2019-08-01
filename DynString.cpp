#include "DynString.h"


	//constructor
	DynString::DynString(char* d)
	{
		int i = 0;
		while (d[i])
		{
			i++;
		}
		size = i;
		Container = new char[size];
		for (int i=0;i<size;i++)
		{
			Container[i] = d[i];
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
		Container = new char[size];
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

	//external addition operator overload
	DynString& DynString::operator+(const DynString &obj)
	{
		char* newContainer = new char[(size + obj.size)];
		
		for (int i = 0; i < size; i++)
		{
			newContainer[i] = Container[i];
		}
		for (int i = 0; i < obj.size; i++)
		{
			newContainer[(size+i)] = obj.Container[i];
		}
		Container = newContainer;
		size += obj.size;
		return *this;
	}

	//copy assignment operator overload
	DynString& DynString::operator=(const DynString &obj)
	{
		if (this != &obj)
		{
			delete[] Container;
			size = obj.size;
			Container = new char[size];
			for (int i = 0; i < size; i++)
			{
				Container[i] = obj.Container[i];
			}
		}

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

	//output content
	void DynString::Show()
	{
		for (int i = 0; i < size; i++)
		{
			cout << Container[i];
		}
	}

	//compare
	bool DynString::IsMore(DynString str)
	{
		int count = str.size;
		if (this->size < str.size)	count = this->size;
		for (int i = 0; i < count; i++)
		{
			if (this->Container[i] != str.Container[i])
			{
				if (this->Container[i] > str.Container[i])	return true;
				return false;
			}
		}
		return false;
	}
	
	


