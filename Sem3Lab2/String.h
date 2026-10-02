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
	explicit String(const char* str = nullptr);

	// Конструктор копирования
	String(const String& other);

	// Деструктор
	~String();

	// Перегрузка операторов сложения
	String operator+(const String& other) const;
	String operator+(const char* other_str) const;
	friend String operator+(const char* str_const, const String& str_object);

	// Перегрузка операторов присваивания
	String& operator=(const String& other);
	String& operator+=(const String& other);
	String& operator+=(const char* str_const);

	// Перегрузка операторов сравнения
	inline bool operator==(const String& other) const;
	inline bool operator>(const String& other) const;
	inline bool operator>=(const String& other) const;
	inline bool operator<(const String& other) const;
	inline bool operator<=(const String& other) const;

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
	String operator()(int start, int end_or_len);
};

//const char* operator+(const char* str_const1, const char* str_const2);