#include <vector>					//use STL example
#include "DynString.h"

using namespace std;

int main()
{
	int testSize = 8;
	string testStrings[8] = {"Charlie","Echo", "Delta","Alpha","Bravo","Foxtrot","Hotel","Golf"};
	
	DynString* testArr = new DynString(testStrings,testSize);
	DynString* newArr = new DynString(*testArr);
	

	cout << "Original array: " << endl;
	testArr->Show();

	
	cout << "Sorted array: " << endl;
	newArr->Sort();
	newArr->Show();

	cout << "Changed arrays: " << endl;

	testArr->AddStr("Julya");
	newArr->DelStr(0);
	testArr->Show();
	newArr->Show();

	cout << "Reverse array: " << endl;

	vector<string> vecArr;

	for (int i = newArr->size - 1; i >= 0; i--)
	{
		vecArr.push_back(newArr->Container[i]);
	}


	for (int i = 0; i < vecArr.size(); i++)
	{
		cout << vecArr[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}