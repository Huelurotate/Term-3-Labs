#include "tourist.h"

Tourist::Tourist(std::string surname, int year, int pass_num,
	std::string h_c, std::string dest, int arr_count) :
	Human(surname, year),
	passport_number(pass_num),
	mig_data_count(arr_count)
{
	this->mig_data_arr[0].home_country = h_c;
	this->mig_data_arr[0].destination = dest;
}

Tourist::~Tourist() {}

int Tourist::get_mig_data_count() const
{
	return this->mig_data_count;
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

void Tourist::set_mig_data_count(int new_count)
{
	this->mig_data_count = new_count;
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

void Tourist::print() const
{
	Human::print();
	std::cout << std::left;
	std::cout << "|" << std::setw(18) << "Passport number:" \
			  << "|" << std::setw(15) << "Home country:" \
			  << "|" << std::setw(15) << "Destination:";
}

std::ostream& operator<<(std::ostream& stream_obj, const Tourist& tourist_obj)
{
	tourist_obj.print();
	stream_obj << std::endl;
	stream_obj << std::left;
	for(int i = 0; i < tourist_obj.get_mig_data_count(); i++)
	{
		stream_obj << "|" << std::setw(15) << (i == 0 ? tourist_obj.get_surname() : "") \
			<< "|" << std::setw(8) << (i == 0 ? std::to_string(tourist_obj.get_year()) : "") \
			<< "|" << std::setw(18) << (i == 0 ? std::to_string(tourist_obj.get_pass_num()) : "") \
			<< "|" << std::setw(15) << tourist_obj.get_home_country(i) \
			<< "|" << std::setw(15) << tourist_obj.get_destination(i);
	}

	return stream_obj;
}

std::istream& operator>>(std::istream& stream_obj, Tourist& tourist_obj)
{
	stream_obj >> dynamic_cast<Human&>(tourist_obj);

	int arr_len;
	int new_pass_num;
	std::string new_home_c, new_dest;

	std::cout << "Enter passport number: ";
	stream_obj >> new_pass_num;
	tourist_obj.set_pass_num(new_pass_num);

	std::cout << "How many trips(home contry -> destination)?: ";
	stream_obj >> arr_len;

	for (int i = 0; (i < arr_len) && i < tourist_obj.MAX_ARR_SIZE; i++)
	{
		std::cout << "Enter home country " << i + 1 << ": ";;
		getline(stream_obj >> std::ws, new_home_c);
		std::cout << "Enter destination " << i + 1 << ": ";;
		getline(stream_obj >> std::ws, new_dest);

		tourist_obj.set_home_country(i, new_home_c);
		tourist_obj.set_destination(i, new_dest);
	}

	tourist_obj.set_mig_data_count(arr_len);

	return stream_obj;
}