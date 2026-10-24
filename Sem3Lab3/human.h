// Яровиков В. Ю.
//1 Вариант
//Человек
//фамилия и год рождения поля
//
//Предприниматель(человек)
//массив(фиксированный) структур где дата и сумма
//
//турист(человек)
//номер паспорта и массив структур(страна куда уехал)
//
//Бизнесмен(турист и предприниматель)
//массив строк(адреса по которым товар покупается)(фиксированный)
//
//все классы имеют геттеры и сеттеры
//должен быть перегружен << >>

#pragma once

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Human
{
private:
	string surname;
	int year;

protected:
	static constexpr int MAX_ARR_SIZE = 10;

public:
	explicit Human(string surname = "", int year = 0);
	virtual ~Human() = default;

	string get_surname() const;
	int get_year() const;

	void set_surname(string new_surname);
	void set_year(int new_year);

	virtual void print() const;

	friend ostream& operator<<(ostream& stream_obj, const Human& human_obj);
	friend istream& operator>>(istream& stream_obj, Human& human_obj);
};