#include "entrepreneur.h"

// Конструктор
Entrepreneur::Entrepreneur(string surname, int year,
	string date, int sum, int arr_count) :
	Human(surname, year),
	tr_data_count(arr_count)
{
	this->tr_data_arr[0].date = date;
	this->tr_data_arr[0].sum = sum;
}

// Геттер кол-во элементов массива
int Entrepreneur::get_tr_data_count() const
{
	return this->tr_data_count;
}

// Геттер даты сделки
string Entrepreneur::get_date(int index) const
{
	return this->tr_data_arr[index].date;
}

// Геттер суммы сделки
int Entrepreneur::get_sum(int index) const
{
	return this->tr_data_arr[index].sum;
}

// Сеттер кол-во элементов массива
void Entrepreneur::set_tr_data_count(int new_count)
{
	this->tr_data_count = new_count;
}

// Сеттер даты сделки
void Entrepreneur::set_date(int index, string new_date)
{
	this->tr_data_arr[index].date = new_date;
}

// Сеттер суммы сделки
void Entrepreneur::set_sum(int index, int new_sum)
{
	this->tr_data_arr[index].sum = new_sum;
}

// Перегруженная функция print
void Entrepreneur::print() const
{
	Human::print();
	cout << left;
	cout << "|" << setw(12) << "Date:" \
		<< "|" << setw(8) << "Sum:";
}

// Перегрузка <<
ostream& operator<<(ostream& stream_obj, const Entrepreneur& entr_obj)
{
	stream_obj << endl;
	stream_obj << left;

	// Вывод, при этом элементы массива выводятся на разных строках
	for (int i = 0; i < entr_obj.get_tr_data_count(); i++)
	{
		stream_obj << "|" << setw(15) << (i == 0 ? entr_obj.get_surname() : "") \
			<< "|" << setw(6) << (i == 0 ? to_string(entr_obj.get_year()) : "")\
			<< "|" << setw(12) << entr_obj.get_date(i) \
			<< "|" << setw(8) << entr_obj.get_sum(i) << endl;
	}

	return stream_obj;
}

// Перегрузка >>
istream& operator>>(istream& stream_obj, Entrepreneur& entr_obj)
{
	// Вызываем оператор >> для Human
	stream_obj >> static_cast<Human&>(entr_obj);

	int arr_len;
	string new_date;
	int new_sum;

	// Спрашиваем сколько элементов будет в массиве
	cout << "How many transactions(date->sum)?: ";
	stream_obj >> arr_len;

	// Циклом просим всё ввести
	for (int i = 0; (i < arr_len) && i < entr_obj.MAX_ARR_SIZE; i++)
	{
		cout << "Enter date " << i + 1 << ": ";;
		getline(stream_obj >> ws, new_date);
		cout << "Enter sum " << i + 1 << ": ";;
		stream_obj >> new_sum;

		// Присваиваем новые значения сеттерами
		entr_obj.set_date(i, new_date);
		entr_obj.set_sum(i, new_sum);
	}

	// Обновляем кол-во элементов в массиве
	entr_obj.set_tr_data_count(arr_len);

	return stream_obj;
}