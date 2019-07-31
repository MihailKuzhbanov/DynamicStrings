#pragma once
#include <iostream>

using namespace std;

class DynString
{
public:
	int size;
	char* Container;
	DynString& operator=(const DynString &obj);
	DynString& operator+(const DynString &obj);
	DynString& operator=(DynString&& obj);
	DynString(char*);
	~DynString();
	DynString(const DynString &obj);
	DynString(DynString &&obj);
	void Show();
	bool IsMore(DynString);
};

