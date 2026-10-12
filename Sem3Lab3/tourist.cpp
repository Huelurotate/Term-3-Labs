#include "tourist.h"

Tourist::Tourist(string surname, int year, string h_c,
	string dest, int pass_num) : Human(surname, year),
	passport_number(pass_num)
{
	arr_count = 0;
	this->mig_data_arr[0].home_country = h_c;
	this->mig_data_arr[0].destination = dest;
}

int Tourist::get_pass_num() const
{
	return this->passport_number;
}

string Tourist::get_home_country(int index) const
{
	return this->mig_data_arr[index].home_country;
}

string Tourist::get_destination(int index) const
{
	return this->mig_data_arr[index].destination;
}

void Tourist::set_pass_num(int new_pass_num)
{
	this->passport_number = new_pass_num;
}

void Tourist::set_home_country(int index, string new_home)
{
	this->mig_data_arr[index].home_country = new_home;
}
void Tourist::set_destination(int index, string new_dest)
{
	this->mig_data_arr[index].destination = new_dest;
}

ostream& operator<<(ostream& stream_obj, const Tourist& tourist_obj)
{
	tourist_obj.print();
	return stream_obj;
}

istream& operator>>(istream& stream_obj, Tourist& tourist_obj)
{
	stream_obj >> static_cast<Human&>(tourist_obj);

	


	return stream_obj;
}