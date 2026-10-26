#pragma once

#include "entrepreneur.h"
#include "tourist.h"

class Businessman : public Entrepreneur, public Tourist
{
private:
	// Кол-во строк в массиве и сам массив
	int adr_arr_count;
	string addresses_arr[MAX_ARR_SIZE];

public:
	// Конструктор и перегруженный деструктор
	explicit Businessman(string surname = "", int year = 0,
		string date = "", int sum = 0, int pass_num = 0,
		string h_c = "", string dest = "",
		string address = "", int arr_count = 0);
	~Businessman() override = default;

	// Геттеры
	int get_adr_arr_count() const;
	string get_address(int index) const;

	// Сеттеры
	void set_adr_arr_count(int new_count);
	void set_address(int index, string new_address);

	// Перегруженная функция print
	void print() const override;

	// Перегрузка << и >>
	friend ostream& operator<<(ostream& stream_obj, const Businessman& bm_obj);
	friend istream& operator>>(istream& stream_obj, Businessman& bm_obj);
};