#include "tourist.h"

// Конструктор
Tourist::Tourist(string surname, int year, int pass_num,
	string h_c, string dest, int arr_count) :
	Human(surname, year),
	passport_number(pass_num),
	mig_data_count(arr_count)
{
	this->mig_data_arr[0].home_country = h_c;
	this->mig_data_arr[0].destination = dest;
}

// Геттер кол-во элементов массива
int Tourist::get_mig_data_count() const
{
	return this->mig_data_count;
}

// Геттер номера пасспорта
int Tourist::get_pass_num() const
{
	return this->passport_number;
}

// Геттер страны откуда едем
string Tourist::get_home_country(int index) const
{
	return this->mig_data_arr[index].home_country;
}

// Геттер страны куда едем
string Tourist::get_destination(int index) const
{
	return this->mig_data_arr[index].destination;
}

// Сеттер кол-во элементов массива
void Tourist::set_mig_data_count(int new_count)
{
	this->mig_data_count = new_count;
}

// Сеттер номера пасспорта
void Tourist::set_pass_num(int new_pass_num)
{
	this->passport_number = new_pass_num;
}

// Сеттер страны откуда едем
void Tourist::set_home_country(int index, string new_home)
{
	this->mig_data_arr[index].home_country = new_home;
}

// Сеттер страны куда едем
void Tourist::set_destination(int index, string new_dest)
{
	this->mig_data_arr[index].destination = new_dest;
}

// Перегруженная функция print
void Tourist::print() const
{
	Human::print();
	cout << left;
	cout << "|" << setw(18) << "Passport number:" \
		 << "|" << setw(15) << "Home country:" \
		 << "|" << setw(15) << "Destination:";
}

// Перегрузка <<
ostream& operator<<(ostream& stream_obj, const Tourist& tourist_obj)
{
	stream_obj << endl;
	stream_obj << left;

	// Вывод, при этом элементы массива выводятся на разных строках
	for(int i = 0; i < tourist_obj.get_mig_data_count(); i++)
	{
		stream_obj << "|" << setw(15) << (i == 0 ? tourist_obj.get_surname() : "") \
			<< "|" << setw(6) << (i == 0 ? to_string(tourist_obj.get_year()) : "") \
			<< "|" << setw(18) << (i == 0 ? to_string(tourist_obj.get_pass_num()) : "") \
			<< "|" << setw(15) << tourist_obj.get_home_country(i) \
			<< "|" << setw(15) << tourist_obj.get_destination(i) << endl;
	}

	return stream_obj;
}

// Перегрузка >>
istream& operator>>(istream& stream_obj, Tourist& tourist_obj)
{
	// Вызываем оператор >> для Human
	stream_obj >> dynamic_cast<Human&>(tourist_obj);

	int arr_len;
	int new_pass_num;
	string new_home_c, new_dest;

	// Принимаем и присваеваем поле номера пасспорта
	cout << "Enter passport number: ";
	stream_obj >> new_pass_num;
	tourist_obj.set_pass_num(new_pass_num);

	// Спрашиваем сколько элементов будет в массиве
	cout << "How many trips(home contry -> destination)?: ";
	stream_obj >> arr_len;

	// Циклом просим всё ввести
	for (int i = 0; (i < arr_len) && i < tourist_obj.MAX_ARR_SIZE; i++)
	{
		cout << "Enter home country " << i + 1 << ": ";;
		getline(stream_obj >> ws, new_home_c);
		cout << "Enter destination " << i + 1 << ": ";;
		getline(stream_obj >> ws, new_dest);

		// Присваиваем новые значения сеттерами
		tourist_obj.set_home_country(i, new_home_c);
		tourist_obj.set_destination(i, new_dest);
	}

	// Обновляем кол-во элементов в массиве
	tourist_obj.set_mig_data_count(arr_len);

	return stream_obj;
}