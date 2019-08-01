#pragma once
#include <iostream>
#include <string>

using namespace std;

class DynString
{
public:
	int size;
	string* Container;
	DynString& operator=(const DynString &obj);
	DynString& operator=(DynString&& obj);
	DynString(int size);
	DynString(string* str, int s);
	~DynString();
	DynString(const DynString &obj);
	DynString(DynString &&obj);
	void AddStr(string newStr);
	void AddStr(string newStr, int index);
	void DelStr(int index);
	void DelStr(string delStr);
	void Show();
	void Sort();
};

