#include <iostream>
#include <string>
#include "String.h"

// Коструктор
String::String(const char* str)
{
	if (str == nullptr) str = "";
	this->len = strlen(str);
	this->str = new char[this->len + 1];
	strcpy(this->str, str);
}

// Коструктор копирования
String::String(const String& other)
{
	this->len = other.len;
	this->str = new char[other.len + 1];
	strcpy(this->str, other.str);
}

// Деструктор
String::~String()
{
	if(str != nullptr) delete[] str;
}

// Перегрузка оператора присваивания
String& String::operator=(const String& other)
{
	if (this == &other) return *this;

	char* temp = new char[other.len + 1];
	strcpy(temp, other.str);

	delete[] this->str;
	this->str = temp;
	this->len = other.len;
	
	return *this;
}

// Перегрузка оператора += (obj + obj)
String& String::operator+=(const String& other)
{
	int new_len = this->len + other.len;
	char* temp = new char[new_len + 1];

	strcpy(temp, this->str);
	strcat(temp, other.str);

	delete[] this->str;

	this->str = temp;
	this->len = new_len;

	return *this;
}

// Перегрузка оператора += (obj + const)
String& String::operator+=(const char* str_const)
{
	int new_len = this->len + strlen(str_const);
	char* temp = new char[new_len + 1];

	strcpy(temp, this->str);
	strcat(temp, str_const);

	delete[] this->str;

	this->str = temp;
	this->len = new_len;

	return *this;
}

// Перегрузка оператора суммы (obj + obj)
String String::operator+(const String& other) const
{
	String result_string;

	result_string.len = this->len + other.len;
	result_string.str = new char[result_string.len + 1];

	strcpy(result_string.str, this->str);
	strcat(result_string.str, other.str);

	return result_string;
}

// Перегрузка оператора суммы (obj + const)
String String::operator+(const char* other_str) const
{
	String result_string;
	
	result_string.len = this->len + strlen(other_str);
	result_string.str = new char[result_string.len + 1];

	strcpy(result_string.str, this->str);
	strcat(result_string.str, other_str);
	
	return result_string;
}

// Перегрузка оператора суммы (const + obj)
String operator+(const char* str_const, const String& str_object)
{
	String result_string;

	result_string.len = strlen(str_const) + str_object.len;
	result_string.str = new char[result_string.len + 1];

	strcpy(result_string.str, str_const);
	strcat(result_string.str, str_object.str);

	return result_string;
}

// Перегрузка оператора суммы (const + const)
//const char* operator+(const char* str_const1, const char* str_const2)
//{
//	String result_string(str_const1);
//	result_string += str_const2;
//	return result_string;
//}

// Перегрузки операторов сравнения
inline bool String::operator>(const String& other) const
{
	return this->len > other.len;
}

inline bool String::operator>=(const String& other) const
{
	return this->len >= other.len;
}

inline bool String::operator<(const String& other) const
{
	return this->len < other.len;
}

inline bool String::operator<=(const String& other) const
{
	return this->len <= other.len;
}

inline bool String::operator==(const String& other) const
{
	return this->len == other.len;
}

// Перегрузка оператора инкремента префиксный
String& String::operator++()
{
	int new_len = this->len + 1;
	char* temp = new char[new_len + 1];

	strcpy(temp, this->str);
	strcat(temp, " ");

	delete[] this->str;

	this->str = temp;
	this->len = new_len;

	return *this;
}

// Перегрузка оператора инкремента постфиксный
String String::operator++(int)
{
	String result_matrix(this->str);

	int new_len = this->len + 1;
	char* temp = new char[new_len + 1];

	strcpy(temp, this->str);
	strcat(temp, " ");

	delete[] this->str;

	this->str = temp;
	this->len = new_len;

	return result_matrix;
}

// Перегрузка оператора декремента префиксный
String& String::operator--()
{
	this->str[this->len - 1] = '\0';
	this->len--;

	return *this;
}

// Перегрузка оператора декремента постфиксный
String String::operator--(int)
{
	String result_matrix(this->str);

	this->str[this->len - 1] = '\0';
	this->len--;

	return result_matrix;
}

// Перегрузка оператора ввода
istream& operator>>(istream& input_stream, String& str_object)
{
	delete[] str_object.str;
	char buffer[1000];

	input_stream.getline(buffer, 1000);

	str_object.str = new char[strlen(buffer) + 1];
	strcpy(str_object.str, buffer);
	str_object.len = strlen(str_object.str);

	return input_stream;
}

// Перегрузка оператора вывода
ostream& operator<<(ostream& output_stream, const String& str_object)
{
	output_stream << str_object.str << endl;
	return output_stream;
}

// Перегрузка оператора []
char String::operator[](int index)
{
	if (index >= 0 && index <= this->len)
		return this->str[index - 1];
}

// Перегрузка оператора ()
String String::operator()(int start, int end_or_len)
{
	if (start < 0 || start > this->len)
		cerr << "Wrong starting index";

	int choice;
	cout << "The second arg is the end or length?(1 - end, 0 - len): ";
	cin >> choice;

	if (choice == 1)
	{
		if (end_or_len < start || end_or_len > this->len)
			cerr << "Wrong end index";

		int new_len = end_or_len - start + 1;
		char* temp = new char[new_len + 1];

		int i = 0, j = 0;
		for (i = start; i <= end_or_len; i++)
			temp[j++] = this->str[i];
		temp[new_len] = '\0';

		String result_string(temp);
		return result_string;
	}
	else if (choice == 0)
	{
		if (end_or_len < 0 || end_or_len > (this->len - (start + 1)))
			cerr << "Wrong length";

		char* temp = new char[end_or_len + 1];

		int i = 0, j = 0;
		for (i = start; j <= end_or_len; i++)
			temp[j++] = this->str[i];
		temp[end_or_len] = '\0';
		
		String result_string(temp);
		return result_string;
	}
	else cerr << "Wrong choice";
}