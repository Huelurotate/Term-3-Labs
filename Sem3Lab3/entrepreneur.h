#pragma once

#include "human.h"

class Entrepreneur : virtual public Human
{
private:
	struct TransactionData
	{
		std::string date;
		int sum;
	};

	int tr_data_count;
	TransactionData tr_data_arr[MAX_ARR_SIZE];

public:
	explicit Entrepreneur(std::string surname = "", int year = 0,
						  std::string date = "", int sum = 0,
						  int arr_count = 0);
	~Entrepreneur() override;

	int get_tr_data_count() const;
	std::string get_date(int index) const;
	int get_sum(int index) const;
	
	void set_tr_data_count(int new_count);
	void set_date(int index, std::string new_date);
	void set_sum(int index, int new_sum);

	void print() const override;

	friend std::ostream& operator<<(std::ostream& stream_obj, const Entrepreneur& entr_obj);
	friend std::istream& operator>>(std::istream& stream_obj, Entrepreneur& entr_obj);
};