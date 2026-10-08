#include <iostream>
#include "String.h"

// Коструктор по умолчанию
String::String(int len) : len(len)
{
	this->str = new char[this->len + 1];
	this->str[len] = '\0';
}

// Коструктор с параметром строкой
String::String(const char* str)
{
	this->len = strlen(str);
	this->str = new char[this->len + 1];
	strcpy(this->str, str);
}

// Коструктор копирования
String::String(const String& other) : String(other.len)
{
	strcpy(this->str, other.str);
}

// Деструктор
String::~String()
{
	delete[] str;
}

// Перегрузка оператора присваивания
String& String::operator=(const String& other)
{
	if (this == &other) return *this;

	delete[] this->str;
	this->str = new char[other.len + 1];

	strcpy(this->str, other.str);
	this->len = other.len;
	
	return *this;
}

// Перегрузка оператора += (obj + obj)
String& String::operator+=(const String& other)
{
	*this = *this + other;
	return *this;
}

// Перегрузка оператора += (obj + const)
String& String::operator+=(const char* str_const)
{
	*this = *this + String(str_const);
	return *this;
}

// Перегрузка оператора -= (obj + obj)
String& String::operator-=(const String& other)
{
	*this = *this - other;
	return *this;
}

// Перегрузка оператора -= (obj + const)
String& String::operator-=(const char* str_const)
{
	*this = *this - String(str_const);
	return *this;
}

// Перегрузка оператора суммы (obj + obj)
String String::operator+(const String& other) const
{
	String result_string = String(this->len + other.len);

	strcpy(result_string.str, this->str);
	strcat(result_string.str, other.str);

	return result_string;
}

// Перегрузка оператора суммы (obj + const)
String String::operator+(const char* str_const) const
{
	return *this + String(str_const);
}

// Перегрузка оператора суммы (const + obj)
String operator+(const char* str_const, const String& str_object)
{
	return String(str_const) + str_object;
}

// Перегрузка оператора вычитания (obj + obj)
String String::operator-(const String& other) const
{
	int min_len = (this->len < other.len) ? this->len : other.len;
	String result_string(this->len + 1);
	for (int i = 0; i < min_len; i++)
	{
		char ch1 = this->str[i];
		char ch2 = other.str[i];
		if (ch1 >= 'a' && ch1 <= 'z' && ch2 >= 'a' && ch2 <= 'z')
		{
			char new_ch = ch1 - ch2;
			if (new_ch < 0) new_ch += 26;
			result_string.str[i] = 'a' + new_ch;
		}
		else if (ch1 >= 'A' && ch1 <= 'Z' && ch2 >= 'A' && ch2 <= 'Z')
		{
			char new_ch = ch1 - ch2;
			if (new_ch < 0) new_ch += 26;
			result_string.str[i] = 'A' + new_ch;
		}
		else if (ch1 >= '0' && ch1 <= '9' && ch2 >= '0' && ch2 <= 'z9')
		{
			char new_ch = ch1 - ch2;
			if (new_ch < 0) new_ch += 10;
			result_string.str[i] = '0' + new_ch;
		}
		else result_string.str[i] = ch1;
	}
	
	for (int i = min_len; i < this->len; i++)
		result_string.str[i] = this->str[i];
	result_string.str[this->len] = '\0';

	return result_string;
}

// Перегрузка оператора вычитания (obj + const)
String String::operator-(const char* str_const) const
{
	String result_string = *this - String(str_const);
	return result_string;
}

// Перегрузка оператора вычитания (const + obj)
String operator-(const char* str_const, const String& str_object)
{
	String result_string = String(str_const) - str_object;
	return result_string;
}

// Перегрузки операторов сравнения
bool String::operator>(const String& other) const
{
	return strcmp(this->str, other.str) > 0;
}

bool String::operator>=(const String& other) const
{
	return strcmp(this->str, other.str) >= 0;
}

bool String::operator<(const String& other) const
{
	return strcmp(this->str, other.str) < 0;
}

bool String::operator<=(const String& other) const
{
	return strcmp(this->str, other.str) <= 0;
}

bool String::operator==(const String& other) const
{
	return strcmp(this->str, other.str) == 0;
}

// Перегрузка оператора инкремента префиксный
String& String::operator++()
{
	for (int i = 0; i < this->len; i++)
	{
		char ch = this->str[i];
		if (ch >= 'a' && ch <= 'z') this->str[i] = (ch == 'z') ? 'a' : ch + 1;
		else if (ch >= 'A' && ch <= 'Z') this->str[i] = (ch == 'Z') ? 'A' : ch + 1;
		else if (ch >= '0' && ch <= '9') this->str[i] = (ch == '9') ? '0' : ch + 1;
	}
	return *this;
}

// Перегрузка оператора инкремента постфиксный
String String::operator++(int)
{
	String result_string = ++(*this);
	return result_string;
}

// Перегрузка оператора декремента префиксный
String& String::operator--()
{
	for (int i = 0; i < this->len; i++)
	{
		char ch = this->str[i];
		if (ch >= 'a' && ch <= 'z') this->str[i] = (ch == 'a') ? 'z' : ch - 1;
		else if (ch >= 'A' && ch <= 'Z') this->str[i] = (ch == 'A') ? 'Z' : ch - 1;
		else if (ch >= '0' && ch <= '9') this->str[i] = (ch == '0') ? '9' : ch - 1;
	}
	return *this;
}

// Перегрузка оператора декремента постфиксный
String String::operator--(int)
{
	String result_string = --(*this);
	return result_string;
}

// Перегрузка оператора ввода
istream& operator>>(istream& input_stream, String& str_object)
{
	char buffer[1024];
	input_stream.getline(buffer, 1024);

	if (buffer)
	{
		delete[] str_object.str;
		str_object.len = strlen(buffer);
		str_object.str = new char[str_object.len + 1];
		strcpy(str_object.str, buffer);
	}

	return input_stream;
}

// Перегрузка оператора вывода
ostream& operator<<(ostream& output_stream, const String& str_object)
{
	if(str_object.str)
		output_stream << str_object.str << endl;
	return output_stream;
}

// Перегрузка оператора []
char String::operator[](int index)
{
	if (index >= 0 && index < this->len)
		return this->str[index];
	return '\0';
}

// Перегрузка оператора ()
String String::operator()(int start, int end)
{
	if (start < 0 || start > this->len) start = 0;
	if (end < 0 || end > this->len) end = this->len - 1;
	if (start > end) return String("");

	int new_len = end - start + 1;
	String result_string(new_len);
	for (int i = 0; i < new_len; i++)
		result_string.str[i] = this->str[start++];
	result_string.str[new_len] = '\0';

	return result_string;
}