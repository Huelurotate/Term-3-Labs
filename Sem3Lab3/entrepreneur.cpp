#include "entrepreneur.h"

Entrepreneur::Entrepreneur(string surname, int year,
	string date = "", int sum = 0) : Human(surname, year)
{
	this->tr_data_arr[0].date = date;
	this->tr_data_arr[0].sum = sum;
}

string Entrepreneur::get_date(int index) const
{
	return this->tr_data_arr[index].date;
}

int Entrepreneur::get_sum(int index) const
{
	return this->tr_data_arr[index].sum;
}

void Entrepreneur::set_date(int index, string new_date)
{
	this->tr_data_arr[index].date = new_date;
}

void Entrepreneur::set_sum(int index, int new_sum)
{
	this->tr_data_arr[index].sum = new_sum;
}

ostream& operator<<(ostream& stream_obj, const Entrepreneur& entr_obj)
{
	entr_obj.print();
	return stream_obj;
}

istream& operator>>(istream& stream_obj, Entrepreneur& entr_obj)
{


	return stream_obj;
}