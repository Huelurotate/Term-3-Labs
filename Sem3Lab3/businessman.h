#pragma once

#include "entrepreneur.h"
#include "tourist.h"

class Businessman : public Entrepreneur, Tourist
{
private:
	std::string addresses_arr[MAX_ARR_SIZE];

public:
	explicit Businessman(std::string surname, int year, 
		std::string date, int sum, int pass_num, std::string h_c,
		std::string dest, std::string address);
	~Businessman();

	std::string get_address(int index) const;

	void set_address(int index, std::string new_address);

	void print() const override;

	friend std::ostream& operator<<(std::ostream& stream_obj, const Businessman& bm_obj);
	friend std::istream& operator>>(std::istream& stream_obj, Businessman& bm_obj);
};