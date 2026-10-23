#include "entrepreneur.h"

Entrepreneur::Entrepreneur(std::string surname, int year,
	std::string date, int sum, int arr_count) : 
	Human(surname, year),
	tr_data_count(arr_count)
{
	this->tr_data_arr[0].date = date;
	this->tr_data_arr[0].sum = sum;
}

Entrepreneur::~Entrepreneur() {}

int Entrepreneur::get_tr_data_count() const
{
	return this->tr_data_count;
}

std::string Entrepreneur::get_date(int index) const
{
	return this->tr_data_arr[index].date;
}

int Entrepreneur::get_sum(int index) const
{
	return this->tr_data_arr[index].sum;
}

void Entrepreneur::set_tr_data_count(int new_count)
{
	this->tr_data_count = new_count;
}

void Entrepreneur::set_date(int index, std::string new_date)
{
	this->tr_data_arr[index].date = new_date;
}

void Entrepreneur::set_sum(int index, int new_sum)
{
	this->tr_data_arr[index].sum = new_sum;
}

void Entrepreneur::print() const
{
	Human::print();
	std::cout << std::left;
	std::cout << "|" << std::setw(12) << "Date:" \
			  << "|" << std::setw(8) << "Sum:";
}

std::ostream& operator<<(std::ostream& stream_obj, const Entrepreneur& entr_obj)
{
	entr_obj.print();

	stream_obj << std::endl;
	stream_obj << std::left;
	for (int i = 0; i < entr_obj.get_tr_data_count(); i++)
	{
		stream_obj << "|" << std::setw(15) << (i == 0 ? entr_obj.get_surname() : "") \
				   << "|" << std::setw(8) << (i == 0 ? std::to_string(entr_obj.get_year()) : "")\
				   << "|" << std::setw(12) << entr_obj.get_date(i) \
				   << "|" << std::setw(8) << entr_obj.get_sum(i);
	}

	return stream_obj;
}

std::istream& operator>>(std::istream& stream_obj, Entrepreneur& entr_obj)
{
	stream_obj >> static_cast<Human&>(entr_obj);

	int arr_len;
	std::string new_date;
	int new_sum;

	std::cout << "How many transactions(date->sum)?: ";
	stream_obj >> arr_len;

	for (int i = 0; (i < arr_len) && i < entr_obj.MAX_ARR_SIZE; i++)
	{
		std::cout << "Enter date " << i + 1 << ": ";;
		getline(stream_obj >> std::ws, new_date);
		std::cout << "Enter sum " << i + 1 << ": ";;
		stream_obj >> new_sum;
		
		entr_obj.set_date(i, new_date);
		entr_obj.set_sum(i, new_sum);
	}

	entr_obj.set_tr_data_count(arr_len);

	return stream_obj;
}