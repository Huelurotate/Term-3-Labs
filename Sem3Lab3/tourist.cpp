#include "tourist.h"

Tourist::Tourist(std::string surname, int year, std::string h_c,
	std::string dest, int pass_num) : Human(surname, year),
	passport_number(pass_num)
{
	this->mig_data_arr[0].home_country = h_c;
	this->mig_data_arr[0].destination = dest;
}

int Tourist::get_pass_num() const
{
	return this->passport_number;
}

std::string Tourist::get_home_country(int index) const
{
	return this->mig_data_arr[index].home_country;
}

std::string Tourist::get_destination(int index) const
{
	return this->mig_data_arr[index].destination;
}

void Tourist::set_pass_num(int new_pass_num)
{
	this->passport_number = new_pass_num;
}

void Tourist::set_home_country(int index, std::string new_home)
{
	this->mig_data_arr[index].home_country = new_home;
}
void Tourist::set_destination(int index, std::string new_dest)
{
	this->mig_data_arr[index].destination = new_dest;
}

std::ostream& operator<<(std::ostream& stream_obj, const Tourist& tourist_obj)
{
	tourist_obj.print();
	return stream_obj;
}

std::istream& operator>>(std::istream& stream_obj, Tourist& tourist_obj)
{
	stream_obj >> static_cast<Human&>(tourist_obj);

	int arr_len;
	int new_pass_num;
	std::string new_home_c, new_dest;

	std::cin >> new_pass_num;

	std::cin >> arr_len;
	for (int i = 0; (i < arr_len) && i < tourist_obj.MAX_ARR_SIZE; i++)
	{
		getline(stream_obj, new_home_c);
		getline(stream_obj, new_dest);
		tourist_obj.mig_data_arr[i].home_country = new_home_c;
		tourist_obj.mig_data_arr[i].destination = new_dest;
	}

	return stream_obj;
}