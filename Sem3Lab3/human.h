#pragma once

#include <iostream>
#include <string>
#include <iomanip>


class Human
{
private:
	std::string surname;
	int year;

protected:
	static constexpr int MAX_ARR_SIZE = 100;

public:
	explicit Human(std::string surname, int year);
	explicit Human();
	virtual ~Human() = default;

	std::string get_surname() const;
	int get_year() const;

	void set_surname(std::string new_surname);
	void set_year(int new_year);

	virtual void print() const;

	friend std::ostream& operator<<(std::ostream& stream_obj, const Human& human_obj);
	friend std::istream& operator>>(std::istream& stream_obj, Human& human_obj);
};

//1 вар
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