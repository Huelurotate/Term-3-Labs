#include "human.h"

// Конструктор
Human::Human(string surname, int year)
	: surname(surname), year(year) {}

// Геттер фамилии
string Human::get_surname() const
{
	return this->surname;
}

// Геттер года рождения
int Human::get_year() const
{
	return this->year;
}

// Сеттер фамилии
void Human::set_surname(string new_surname)
{
	this->surname = new_surname;
}

// Сеттер года рождения
void Human::set_year(int new_year)
{
	this->year = new_year;
}

// Виртуальная функция print
void Human::print() const
{
	cout << endl;
	cout << left;
	cout << "|" << setw(15) << "Surname:" \
		<< "|" << setw(6) << "Year:";
}

// Перегрузка <<
ostream& operator<<(ostream& stream_obj, const Human& human_obj)
{
	stream_obj << endl;
	stream_obj << left;
	stream_obj << "|" << setw(15) << human_obj.get_surname() \
		<< "|" << setw(6) << human_obj.get_year() << endl;
	return stream_obj;
}

// Перегрузка >>
istream& operator>>(istream& stream_obj, Human& human_obj)
{
	string new_surname;
	int new_year;

	cout << "Enter surname: ";
	getline(stream_obj >> ws, new_surname);

	cout << "Enter year: ";
	stream_obj >> new_year;

	// Присваиваем значения через сеттеры
	human_obj.set_surname(new_surname);
	human_obj.set_year(new_year);

	return stream_obj;
}