#pragma once

#include "human.h"

class Tourist : virtual public Human
{
private:
	struct MigrationData
	{
		std::string home_country;
		std::string destination;
	};

	int passport_number;
	MigrationData mig_data_arr[MAX_ARR_SIZE];

public:
	explicit Tourist(std::string surname, int year, std::string h_c,
		std::string dest, int pass_num);
	~Tourist();

	int get_pass_num() const;
	std::string get_home_country(int index) const;
	std::string get_destination(int index) const;

	void set_pass_num(int new_pass_num);
	void set_home_country(int index, std::string new_home);
	void set_destination(int index, std::string new_dest);

	void print() const override;

	friend std::ostream& operator<<(std::ostream& stream_obj, const Tourist& tourist_obj);
	friend std::istream& operator>>(std::istream& stream_obj, Tourist& tourist_obj);
};