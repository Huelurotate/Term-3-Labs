#pragma once

#include "human.h"

class Entrepreneur : virtual public Human
{
private:
	struct TransactionData
	{
		string date;
		int sum;
	};

	int tr_data_count;
	TransactionData tr_data_arr[MAX_ARR_SIZE];

public:
	explicit Entrepreneur(string surname = "", int year = 0,
						  string date = "", int sum = 0,
						  int arr_count = 0);
	~Entrepreneur() override;

	int get_tr_data_count() const;
	string get_date(int index) const;
	int get_sum(int index) const;
	
	void set_tr_data_count(int new_count);
	void set_date(int index, string new_date);
	void set_sum(int index, int new_sum);

	void print() const override;

	friend ostream& operator<<(ostream& stream_obj, const Entrepreneur& entr_obj);
	friend istream& operator>>(istream& stream_obj, Entrepreneur& entr_obj);
};