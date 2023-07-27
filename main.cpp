#include <iostream>
#include "my_string.h"

int main()
{
	MyString str1, str2, str3;
	str1 = "Hello ";
	str2 = "world!";
	str3 = str1 + str2;
	str3.Print();

	return 0;
}