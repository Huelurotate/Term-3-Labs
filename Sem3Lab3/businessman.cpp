#include "businessman.h"

// Конструктор
Businessman::Businessman(string surname, int year, 
		string date, int sum, int pass_num, string h_c,
		string dest, string address, int arr_count) :
		Human(surname, year),
		Entrepreneur(surname, year, date, sum, arr_count),
		Tourist(surname, year, pass_num, h_c, dest, arr_count)
{
	this->addresses_arr[0] = address;
}

// Геттер кол-ва значений в массиве
int Businessman::get_adr_arr_count() const
{
	return this->adr_arr_count;
}

// Геттер элемента из массива
string Businessman::get_address(int index) const
{
	return this->addresses_arr[index];
}

// Сеттер кол-ва значений в массиве
void Businessman::set_adr_arr_count(int new_count)
{
	this->adr_arr_count = new_count;
}

// Геттер элемента из массива
void Businessman::set_address(int index, string new_address)
{
	this->addresses_arr[index] = new_address;
}

// Перегруженная функция print
void Businessman::print() const
{
	Entrepreneur::print();
	cout << left;
	cout << "|" << setw(15) << "Home country:" \
		 << "|" << setw(15) << "Destination:" \
		 << "|" << setw(10) << "Address:";
}

// Перегрузка <<
ostream& operator<<(ostream& stream_obj, const Businessman& bm_obj)
{
	stream_obj << endl;
	stream_obj << left;

	// Вычисляем кол-во строк в таблице
	int rows = max({1, bm_obj.get_adr_arr_count(),
					   bm_obj.get_mig_data_count(),
					   bm_obj.get_tr_data_count()});

	// Вывод, при этом элементы массива выводятся на разных строках
	for (int i = 0; i < rows; i++)
	{
		stream_obj << "|" << setw(15) << (i == 0 ? bm_obj.get_surname() : "") \
			<< "|" << setw(6) << (i == 0 ? to_string(bm_obj.get_year()) : "") \
			<< "|" << setw(12) << bm_obj.get_date(i) \
			<< "|" << setw(8) << bm_obj.get_sum(i) \
			<< "|" << setw(18) << (i == 0 ? to_string(bm_obj.get_pass_num()) : "") \
			<< "|" << setw(15) << bm_obj.get_home_country(i) \
			<< "|" << setw(15) << bm_obj.get_destination(i) \
			<< "|" << setw(10) << bm_obj.get_address(i) << endl;
	}

	return stream_obj;
}

// Перегрузка >>
istream& operator>>(istream& stream_obj, Businessman& bm_obj)
{
	// Вызываем оператор >> для Entrepreneur(поля Tourist введём отдельно)
	stream_obj >> dynamic_cast<Entrepreneur&>(bm_obj);

	// Вводим и присваиваем значения для полей класса Tourist
	int tourist_arr_len, bm_arr_len;
	int new_pass_num;
	string new_home_c, new_dest, new_address;

	cout << "Enter passport number: ";
	stream_obj >> new_pass_num;
	bm_obj.set_pass_num(new_pass_num);

	cout << "How many trips(home contry -> destination)?: ";
	stream_obj >> tourist_arr_len;

	for (int i = 0; (i < tourist_arr_len) && i < bm_obj.MAX_ARR_SIZE; i++)
	{
		cout << "Enter home country " << i + 1 << ": ";
		getline(stream_obj >> ws, new_home_c);
		cout << "Enter destination " << i + 1 << ": ";
		getline(stream_obj >> ws, new_dest);

		bm_obj.set_home_country(i, new_home_c);
		bm_obj.set_destination(i, new_dest);
	}

	// Теперь вводим кол-во элементов в массиве класса Businessman и сам элементы
	cout << "How many addresses?: ";
	stream_obj >> bm_arr_len;

	for (int i = 0; (i < bm_arr_len) && i < bm_obj.MAX_ARR_SIZE; i++)
	{
		cout << "Enter address " << i + 1 << ": ";;
		stream_obj >> new_address;
		bm_obj.set_address(i, new_address);
	}

	// Обновляем кол-во элементов в массивах
	bm_obj.set_mig_data_count(tourist_arr_len);
	bm_obj.set_adr_arr_count(bm_arr_len);

	return stream_obj;
}