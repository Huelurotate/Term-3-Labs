#pragma once

#include <iostream>
using namespace std;

class String
{
private:
	char* str;
	int len;
	
public:
	// Конструктор
	explicit String(int len = 0);

	// Коструктор с параметром строкой
	explicit String(const char* str);

	// Конструктор копирования
	String(const String& other);

	// Деструктор
	~String();

	// Перегрузка операторов присваивания
	String& operator=(const String& other);
	String& operator+=(const String& other);
	String& operator+=(const char* str_const);
	String& operator-=(const String& other);
	String& operator-=(const char* str_const);

	// Перегрузка операторов сложения
	String operator+(const String& other) const;
	String operator+(const char* str_const) const;
	friend String operator+(const char* str_const, const String& str_object);

	// Перегрузка операторов вычитания
	String operator-(const String& other) const;
	String operator-(const char* str_const) const;
	friend String operator-(const char* str_const, const String& str_object);

	// Перегрузка операторов сравнения
	bool operator==(const String& other) const;
	bool operator>(const String& other) const;
	bool operator>=(const String& other) const;
	bool operator<(const String& other) const;
	bool operator<=(const String& other) const;

	// Перегрузка операторов инкремента и декремента
	String& operator++();
	String operator++(int);
	String& operator--();
	String operator--(int);

	// Перегрузка операторов ввода и вывода
	friend istream& operator>>(istream& input_stream, String& str_object);
	friend ostream& operator<<(ostream& output_stream, const String& str_object);

	// Перегрузка операторов [] и ()
	char operator[](int index);
	String operator()(int start, int end);
};
