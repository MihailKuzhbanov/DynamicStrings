#include <vector>					//for STL example
#include "DynString.h"

using namespace std;

vector<DynString> Input(int count)
{
	const int maxSize = 256;
	char* inputBuffer = new char[maxSize]();
	vector<DynString> result;
	for (int i = 0; i < count; i++)
	{
		cin.getline(inputBuffer, maxSize, '\n');
		result.push_back(DynString(inputBuffer));
	}
	return result;
}

void Print(vector<DynString> data)
{
	for (DynString element : data)
	{
		element.Show();
		cout << " ";
	}
	cout << endl;
}

void Sort(vector<DynString>& input)
{
		for (int i = 0; i < input.size(); i++)
		{
			for (int j = 0; j < input.size(); j++)
			{
				if (input[i].IsMore(input[j]))
				{
					DynString temp = input[i];
					input[i] = input[j];
					input[j] = temp;
				}
			}

		}
}



int main()
{
	const int steps = 5;
	cout << "Enter strings:" << endl;
	vector<DynString> vecStr = Input(steps);
	cout << "Original array: " << endl;
	Print(vecStr);
	Sort(vecStr);
	cout << "Sorted array: " << endl;
	Print(vecStr);
	cout << endl;

	system("pause");
	return 0;
}