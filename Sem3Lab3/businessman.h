#pragma once

#include "entrepreneur.h"
#include "tourist.h"

class Businessman : public Entrepreneur, Tourist
{
private:
	string adresses_arr[MAX_ARR_SIZE];

public:
	Businessman(string date = "", int sum = 0);
	~Businessman();

	string get_address_data(int index) const;

	void set_address_data(int index, string new_address);

	void print() const override;

	friend ostream& operator<<(ostream& stream_obj, const Businessman& bm_obj);
	friend istream& operator>>(istream& stream_obj, Businessman& bm_obj);
};