#ifndef MY_STRING_H_
#define MY_STRING_H_
#include <iostream>

class MyString
{
public:
	MyString();
	MyString(const char* str);
	~MyString() { delete[] this->str; }

	MyString(const MyString& other);
	MyString(MyString&& other);

	MyString& operator = (const MyString& other);
	MyString operator + (const MyString& other);
	bool operator == (const MyString& other);
	bool operator != (const MyString& other) { return !(this->operator==(other)); }
	char& operator [] (int index) { return this->str[index]; }

	void Print() { std::cout << str << std::endl; }
	int Length() { return length; }
private:
	char* str;
	int length;
};

#endif // MY_STRING_H_