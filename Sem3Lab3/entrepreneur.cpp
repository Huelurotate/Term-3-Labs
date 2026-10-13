#include "entrepreneur.h"

Entrepreneur::Entrepreneur(std::string surname, int year,
	std::string date = "", int sum = 0) : Human(surname, year)
{
	this->tr_data_arr[0].date = date;
	this->tr_data_arr[0].sum = sum;
}

std::string Entrepreneur::get_date(int index) const
{
	return this->tr_data_arr[index].date;
}

int Entrepreneur::get_sum(int index) const
{
	return this->tr_data_arr[index].sum;
}

void Entrepreneur::set_date(int index, std::string new_date)
{
	this->tr_data_arr[index].date = new_date;
}

void Entrepreneur::set_sum(int index, int new_sum)
{
	this->tr_data_arr[index].sum = new_sum;
}

std::ostream& operator<<(std::ostream& stream_obj, const Entrepreneur& entr_obj)
{
	entr_obj.print();
	return stream_obj;
}

std::istream& operator>>(std::istream& stream_obj, Entrepreneur& entr_obj)
{
	stream_obj >> static_cast<Human&>(entr_obj);

	int arr_len;

	std::string new_date;
	int new_sum;

	std::cin >> arr_len;
	for (int i = 0; (i < arr_len) && i < entr_obj.MAX_ARR_SIZE; i++)
	{
		getline(stream_obj, new_date);
		std::cin >> new_sum;
		entr_obj.tr_data_arr[i].date = new_date;
		entr_obj.tr_data_arr[i].sum = new_sum;
	}

	return stream_obj;
}