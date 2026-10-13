#pragma once

#include "entrepreneur.h"
#include "tourist.h"

class Businessman : public Entrepreneur, Tourist
{
private:
	std::string adresses_arr[MAX_ARR_SIZE];

public:
	explicit Businessman(std::string surname, int year, 
		std::string date, int sum, std::string address);
	~Businessman();

	std::string get_address_data(int index) const;

	void set_address_data(int index, std::string new_address);

	void print() const override;

	friend std::ostream& operator<<(std::ostream& stream_obj, const Businessman& bm_obj);
	friend std::istream& operator>>(std::istream& stream_obj, Businessman& bm_obj);
};