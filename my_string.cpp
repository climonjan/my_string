#include "my_string.h"

MyString::MyString()
{
	str = nullptr;
	length = 0;
}

MyString::MyString(const char* str)
{
	length = strlen(str);
	this->str = new char[length + 1];

	for (int i = 0; i < length; i++)
		this->str[i] = str[i];

	this->str[length] = '\0';
}

MyString::MyString(const MyString& other)
{
	length = strlen(other.str);
	this->str = new char[length + 1];

	for (int i = 0; i < length; i++)
		this->str[i] = other.str[i];

	this->str[length] = '\0';
}

MyString::MyString(MyString&& other)
{
	this->length = other.length;
	this->str = other.str;
	other.str = nullptr;
}

MyString& MyString::operator=(const MyString& other)
{
	if (this->str != nullptr)
		delete[] str;

	length = strlen(other.str);
	this->str = new char[length + 1];

	for (int i = 0; i < length; i++)
		this->str[i] = other.str[i];

	this->str[length] = '\0';

	return *this;
}

MyString MyString::operator+(const MyString& other)
{
	MyString newStr;

	int thisLength = strlen(this->str);
	int otherLength = strlen(other.str);

	newStr.length = thisLength + otherLength;
	newStr.str = new char[thisLength + otherLength + 1];

	int i = 0;

	for (; i < thisLength; i++)
		newStr.str[i] = this->str[i];

	for (int j = 0; j < otherLength; j++, i++)
		newStr.str[i] = other.str[j];

	newStr.str[thisLength + otherLength] = '\0';

	return newStr;
}

bool MyString::operator==(const MyString& other)
{
	if (this->length != other.length)
		return false;

	for (int i = 0; i < length; i++)
	{
		if (this->str[i] != other.str[i])
			return false;
	}

	return true;
}
