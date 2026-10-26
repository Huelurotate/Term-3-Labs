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

	// Кол-во элементов в массиве структур и сам массив
	int mig_data_count;
	MigrationData mig_data_arr[MAX_ARR_SIZE];

public:
	// Конструктор и перегруженный деструктор
	explicit Tourist(string surname = "", int year = 0,
		int pass_num = 0, string h_c = "",
		string dest = "", int arr_count = 0);
	~Tourist() override = default;

	// Геттеры
	int get_mig_data_count() const;
	int get_pass_num() const;
	string get_home_country(int index) const;
	string get_destination(int index) const;

	// Сеттеры
	void set_mig_data_count(int new_count);
	void set_pass_num(int new_pass_num);
	void set_home_country(int index, string new_home);
	void set_destination(int index, string new_dest);

	// Перегруженная функция print
	void print() const override;

	// Перегрузка << и >>
	friend ostream& operator<<(ostream& stream_obj, const Tourist& tourist_obj);
	friend istream& operator>>(istream& stream_obj, Tourist& tourist_obj);
};