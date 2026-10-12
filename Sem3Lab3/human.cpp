#include "human.h"

Human::Human(string surname = "", int year = 0)
	: surname(surname), year(year)
{}

string Human::get_surname() const
{
	return this->surname;
}

int Human::get_year() const
{
	return this->year;
}

void Human::set_surname(string new_surname)
{
	this->surname = new_surname;
}

void Human::set_year(int new_year)
{
	this->year = new_year;
}

void Human::print() const
{
	cout << "Surname: " << this->get_surname();
	cout << "Surname: " << this->get_year();
}

ostream& operator<<(ostream& stream_obj, const Human& human_obj)
{
	human_obj.print();
	return stream_obj;
}

istream& operator>>(istream& stream_obj, Human& human_obj)
{
	string new_surname;
	int new_year;

	stream_obj >> new_year;
	getline(stream_obj, new_surname);

	human_obj.set_surname(new_surname);
	human_obj.set_year(new_year);
	return stream_obj;
}