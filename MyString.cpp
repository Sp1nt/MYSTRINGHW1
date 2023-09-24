#include <iostream>
#include "MyString.h"


using namespace std;

// default constructor that allows you to create a string of 80 characters;
MyString::MyString()
{
	AmountOBJ++;
	length = 80;
	str = new char[length + 1];
	str[0] = '\0';
}

//a constructor that allows you to create a string of arbitrary size;
MyString::MyString(int l)
{
	AmountOBJ++;
	length = l;
	str = new char[length + 1];
	str[0] = '\0';
}
//a constructor that creates a string and initializes it with the string received from the user.
MyString::MyString(const char* c)
{
	AmountOBJ++;
	length = strlen(c) + 1;
	str = new char[length];
	strcpy_s(str, strlen(c) + 1, c);
}

MyString::MyString(const MyString& obj) {

	if (obj.str != nullptr)
	{
		length = obj.length;
		str = new char[length + 1];
		strcpy_s(str, length + 1, obj.str);
	}
	AmountOBJ++;
	cout << "Copy constructor\n";
}

//destructor;
MyString::~MyString()
{
	if (str != nullptr)
	{
		delete[] str;
		str = nullptr;
	}
	cout << "Destructor" << endl;
}

void MyString::Input()
{
	char tmpStr[1000];

	cout << "Input text: ";
	cin.getline(tmpStr, sizeof(tmpStr));
	if (str != nullptr)
	{
		delete[] str;
	}

	length = strlen(tmpStr);
	str = new char[strlen(tmpStr) + 1];
	strcpy_s(str, strlen(tmpStr) + 1, tmpStr);
}

void MyString::Print() const
{
	cout << "Your text: " << str << endl;
}
//copying string
void MyString::MyStrcpy(MyString& obj)
{
	if (str != nullptr)
	{
		delete[]str;
	}

	length = obj.length + 1;
	str = new char[strlen(obj.str) + 1];
	strcpy_s(str, strlen(obj.str) + 1, obj.str);
	cout << "Copy constructor\n";

}
//searching for a substring in a string
bool MyString::MyStrStr(const char* str)
{
	int i = 0, j = 0;

	while (this->str[i] != '\0') {
		if (this->str[i] == str[j]) {
			while (this->str[i] == str[j]) {
				i++;
				j++;
			}

			if (str[j] == '\0')
				return true;
		}
		else
			i++;
	}

	return false;
}
//search for a character in a string (index of the found character, or -1)
int MyString::MyChr(char b)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == b)
		{
			return i;
		}
	}
	return -1;
}
//returns the length of the string
int MyString::MyStrLen()
{
	if (str != nullptr) {
		return strlen(str);
	}
	return 0;
}
//string concatenation
void MyString::MyStrCat(MyString& b)
{
	int newLen = length + b.length;
	char* newStr = new char[newLen + 1];

	for (int i = 0; i < length; i++)
	{
		newStr[i] = str[i];
	}

	for (int i = 0; i < b.length; i++)
	{
		newStr[length + i - 1] = b.str[i];
	}

	newStr[newLen] = '\0';

	delete[] str;
	str = newStr;
	length = newLen - 1;
}

//removes the specified symbol
void MyString::MyDelChr(char c)
{
	int newSize = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != c)
		{
			str[newSize++] = str[i];
		}
	}
	str[newSize] = '\0';
	length = newSize;
}
//string comparison
int MyString::MyStrCmp(MyString& b)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] > b.str[i])
		{
			return 1;
		}
		else if (str[i] < b.str[i])
		{
			return -1;
		}
	}

	return 0;
}
