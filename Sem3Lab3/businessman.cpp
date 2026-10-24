#include "businessman.h"

Businessman::Businessman(std::string surname, int year, 
		std::string date, int sum, int pass_num, std::string h_c,
		std::string dest, std::string address, int arr_count) :
		Human(surname, year),
		Entrepreneur(surname, year, date, sum, arr_count),
		Tourist(surname, year, pass_num, h_c, dest, arr_count)
{
	this->addresses_arr[0] = address;
}

Businessman::~Businessman() {}

int Businessman::get_adr_arr_count() const
{
	return this->adr_arr_count;
}

std::string Businessman::get_address(int index) const
{
	return this->addresses_arr[index];
}

void Businessman::set_adr_arr_count(int new_count)
{
	this->adr_arr_count = new_count;
}

void Businessman::set_address(int index, std::string new_address)
{
	this->addresses_arr[index] = new_address;
}

void Businessman::print() const
{
	Tourist::print();
	std::cout << std::left;
	std::cout << "|" << std::setw(12) << "Date:" \
			  << "|" << std::setw(8) << "Sum:" \
			  << "|" << std::setw(10) << "Address:";
}

std::ostream& operator<<(std::ostream& stream_obj, const Businessman& bm_obj)
{
	stream_obj << std::endl;
	stream_obj << std::left;
	int rows = std::max({1, bm_obj.get_adr_arr_count(),
						bm_obj.get_mig_data_count(),
						bm_obj.get_tr_data_count()});

	for (int i = 0; i < rows; i++)
	{
		stream_obj << "|" << std::setw(15) << (i == 0 ? bm_obj.get_surname() : "") \
			<< "|" << std::setw(8) << (i == 0 ? std::to_string(bm_obj.get_year()) : "") \
			<< "|" << std::setw(12) << bm_obj.get_date(i) \
			<< "|" << std::setw(8) << bm_obj.get_sum(i) \
			<< "|" << std::setw(18) << (i == 0 ? std::to_string(bm_obj.get_pass_num()) : "") \
			<< "|" << std::setw(15) << bm_obj.get_home_country(i) \
			<< "|" << std::setw(15) << bm_obj.get_destination(i) \
			<< "|" << std::setw(10) << bm_obj.get_address(i) << std::endl;
	}

	return stream_obj;
}

std::istream& operator>>(std::istream& stream_obj, Businessman& bm_obj)
{
	stream_obj >> dynamic_cast<Entrepreneur&>(bm_obj);

	int tourist_arr_len, bm_arr_len;
	int new_pass_num;
	std::string new_home_c, new_dest, new_address;

	std::cout << "Enter passport number: ";
	stream_obj >> new_pass_num;
	bm_obj.set_pass_num(new_pass_num);

	std::cout << "How many trips(home contry -> destination)?: ";
	stream_obj >> tourist_arr_len;

	for (int i = 0; (i < tourist_arr_len) && i < bm_obj.MAX_ARR_SIZE; i++)
	{
		std::cout << "Enter home country " << i + 1 << ": ";
		getline(stream_obj >> std::ws, new_home_c);
		std::cout << "Enter destination " << i + 1 << ": ";
		getline(stream_obj >> std::ws, new_dest);

		bm_obj.set_home_country(i, new_home_c);
		bm_obj.set_destination(i, new_dest);
	}

	std::cout << "How many addresses?: ";
	stream_obj >> bm_arr_len;

	for (int i = 0; (i < bm_arr_len) && i < bm_obj.MAX_ARR_SIZE; i++)
	{
		std::cout << "Enter address " << i + 1 << ": ";;
		stream_obj >> new_address;
		bm_obj.set_address(i, new_address);
	}

	bm_obj.set_mig_data_count(tourist_arr_len);
	bm_obj.set_adr_arr_count(bm_arr_len);

	return stream_obj;
}