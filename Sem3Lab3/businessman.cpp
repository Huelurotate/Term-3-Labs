#include "businessman.h"

Businessman::Businessman(std::string surname, int year, 
		std::string date, int sum, int pass_num, std::string h_c,
		std::string dest, std::string address) :
		Entrepreneur(surname, year, date, sum), 
		Tourist(surname, year, h_c, dest, pass_num)
{
	this->addresses_arr[0] = address;
}

std::string Businessman::get_address(int index) const
{
	return this->addresses_arr[index];
}

void Businessman::set_address(int index, std::string new_address)
{
	this->addresses_arr[index] = new_address;
}

std::ostream& operator<<(std::ostream& stream_obj, const Businessman& bm_obj)
{
	bm_obj.print();
	return stream_obj;
}

std::istream& operator>>(std::istream& stream_obj, Businessman& bm_obj)
{
	stream_obj >> dynamic_cast<Entrepreneur&>(bm_obj);
	stream_obj >> dynamic_cast<Tourist&>(bm_obj);

	int arr_len;
	std::string new_address;

	std::cout << "Enter array size: ";
	stream_obj >> arr_len;

	for (int i = 0; (i < arr_len) && i < bm_obj.MAX_ARR_SIZE; i++)
	{
		std::cout << "Enter an address: ";
		stream_obj >> new_address;
		bm_obj.set_address(i, new_address);
	}

	return stream_obj;
}