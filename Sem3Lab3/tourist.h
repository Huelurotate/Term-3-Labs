#pragma once

#include "human.h"

class Tourist : virtual public Human
{
private:
	struct MigrationData
	{
		string home_country;
		string destination;
	};

	int passport_number;
	MigrationData mig_data_arr[MAX_ARR_SIZE];
	static int arr_count;

public:
	Tourist(string surname = "", int year, string h_c = "", 
		    string dest = "", int pass_num = 0);
	~Tourist();

	int get_pass_num() const;
	string get_home_country(int index) const;
	string get_destination(int index) const;

	void set_pass_num(int new_pass_num);
	void set_home_country(int index, string new_home);
	void set_destination(int index, string new_dest);

	void print() const override;

	friend ostream& operator<<(ostream& stream_obj, const Tourist& tourist_obj);
	friend istream& operator>>(istream& stream_obj, Tourist& tourist_obj);
};