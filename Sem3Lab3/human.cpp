#include "human.h"

Human::Human(std::string surname = "", int year = 0)
	: surname(surname), year(year)
{}

std::string Human::get_surname() const
{
	return this->surname;
}

int Human::get_year() const
{
	return this->year;
}

void Human::set_surname(std::string new_surname)
{
	this->surname = new_surname;
}

void Human::set_year(int new_year)
{
	this->year = new_year;
}

void Human::print() const
{
	std::cout << "Surname: " << this->get_surname();
	std::cout << "Surname: " << this->get_year();
}

std::ostream& operator<<(std::ostream& stream_obj, const Human& human_obj)
{
	human_obj.print();
	return stream_obj;
}

std::istream& operator>>(std::istream& stream_obj, Human& human_obj)
{
	std::string new_surname;
	int new_year;

	stream_obj >> new_year;
	getline(stream_obj, new_surname);

	human_obj.set_surname(new_surname);
	human_obj.set_year(new_year);
	return stream_obj;
}