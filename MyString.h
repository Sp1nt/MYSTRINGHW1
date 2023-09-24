#pragma once
#include <iostream>
using namespace std;

class MyString
{
	char* str;
	int length;

public:
	static int AmountOBJ;
	MyString();
	MyString(int);
	MyString(const char*);
	MyString(const MyString& obj);
	~MyString();


	void Input();
	void Print() const;

	void MyStrcpy(MyString& obj);
	bool MyStrStr(const char* str);
	int MyChr(char c);
	int MyStrLen();
	void MyStrCat(MyString& b);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);

};

