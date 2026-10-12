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

	TransactionData tr_data_arr[MAX_ARR_SIZE];

public:
	Entrepreneur(string surname, int year, string date = "", int sum = 0);
	~Entrepreneur();

	string get_date(int index) const;
	int get_sum(int index) const;

	void set_date(int index, string new_date);
	void set_sum(int index, int new_sum);

	void print() const override;

	friend ostream& operator<<(ostream& stream_obj, const Entrepreneur& entr_obj);
	friend istream& operator>>(istream& stream_obj, Entrepreneur& entr_obj);
};