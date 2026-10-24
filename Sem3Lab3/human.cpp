#include "human.h"

Human::Human(std::string surname, int year)
	: surname(surname), year(year) {}

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
	std::cout << std::endl;
	std::cout << std::left;
	std::cout << "|" << std::setw(15) << "Surname:" \
			  << "|" << std::setw(6) << "Year:";
}

std::ostream& operator<<(std::ostream& stream_obj, const Human& human_obj)
{
	stream_obj << std::endl;
	stream_obj << std::left;
	stream_obj << "|" << std::setw(15) << human_obj.get_surname() \
			   << "|" << std::setw(6) << human_obj.get_year() << std::endl;
	return stream_obj;
}

std::istream& operator>>(std::istream& stream_obj, Human& human_obj)
{
	std::string new_surname;
	int new_year;

	std::cout << "Enter surname: ";
	getline(stream_obj >> std::ws, new_surname);

	std::cout << "Enter year: ";
	stream_obj >> new_year;

	human_obj.set_surname(new_surname);
	human_obj.set_year(new_year);

	return stream_obj;
}