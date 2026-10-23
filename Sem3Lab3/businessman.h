#pragma once

#include "entrepreneur.h"
#include "tourist.h"

class Businessman : public Entrepreneur, public Tourist
{
private:
	int adr_arr_count;
	std::string addresses_arr[MAX_ARR_SIZE];

public:
	explicit Businessman(std::string surname = "", int year = 0,
		std::string date = "", int sum = 0, int pass_num = 0, 
		std::string h_c = "", std::string dest = "", 
		std::string address = "", int arr_count = 0);
	~Businessman() override;

	int get_adr_arr_count() const;
	std::string get_address(int index) const;

	void set_adr_arr_count(int new_count);
	void set_address(int index, std::string new_address);

	void print() const override;

	friend std::ostream& operator<<(std::ostream& stream_obj, const Businessman& bm_obj);
	friend std::istream& operator>>(std::istream& stream_obj, Businessman& bm_obj);
};