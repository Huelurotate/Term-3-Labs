#include <typeinfo>

#include "human.h"
#include "entrepreneur.h"
#include "tourist.h"
#include "businessman.h"

#include "ring.h"

void lab3_menu();
void lab4_menu();

template <typename T>
void ring_menu(Ring<T>& ring, const string& class_name);

int main()
{
	bool is_running = true;
	while (is_running)
	{
		cout << "\n       Main menu" << endl;
		cout << "1. Lab 3 (Inheritance);" << endl;
		cout << "2. Lab 4 (Templates, Ring);" << endl;
		cout << "3. Exit." << endl;

		int choice;
		cout << "Your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1: 
			lab3_menu(); 
			break;
		case 2: 
			lab4_menu(); 
			break;
		case 3: 
			is_running = false; 
			break;
		}
	}

	return 0;
}

void lab3_menu()
{
	// Объявляем массив объектов Human и переменную кол-ва объектов
	Human* obj_array[100];
	int arr_count = 0;

	// Главный цикл программы
	bool is_running = true;
	while (is_running)
	{
		// Меню
		cout << "\n         Menu" << endl;
		cout << "1. Add a Human object;" << endl;
		cout << "2. Add an Entrepreneur object;" << endl;
		cout << "3. Add a Tourist object;" << endl;
		cout << "4. Add a Businessman object;" << endl;
		cout << "5. Print all objects;" << endl;
		cout << "6. Back." << endl;

		int choice;
		cout << "Your choice: ";
		cin >> choice;

		if (choice >= 1 && choice <= 4 && arr_count >= 100)
		{
			cout << "Array is full." << endl;
			continue;
		}

		switch (choice)
		{
			// Создаём(динамически) объект выбранного класса, выводим его(case 1-4)
		case 1:
		{
			Human* new_human = new Human;
			cin >> *new_human;
			obj_array[arr_count++] = new_human;

			new_human->print();
			cout << *new_human;
			break;
		}
		case 2:
		{
			Entrepreneur* new_entr = new Entrepreneur;
			cin >> *new_entr;
			obj_array[arr_count++] = new_entr;

			new_entr->print();
			cout << *new_entr;
			break;
		}
		case 3:
		{
			Tourist* new_tourist = new Tourist;
			cin >> *new_tourist;
			obj_array[arr_count++] = new_tourist;

			new_tourist->print();
			cout << *new_tourist;
			break;
		}
		case 4:
		{
			Businessman* new_bm = new Businessman;
			cin >> *new_bm;
			obj_array[arr_count++] = new_bm;

			new_bm->print();
			cout << *new_bm;
			break;
		}
		// Вывод всех значений
		case 5:
		{
			if (arr_count == 0)
			{
				cout << "No objects yet." << endl;
				break;
			}

			// массив типов(классов)
			const type_info* types[4] = { &typeid(Human), &typeid(Entrepreneur),
											   &typeid(Tourist), &typeid(Businessman) };

			for (int t = 0; t < 4; t++)
			{
				bool header_printed = false;

				for (int i = 0; i < arr_count; i++)
				{
					if (typeid(*obj_array[i]) != *types[t])
						continue;

					// Для каждого типа объекта шапка один раз выводится
					if (!header_printed)
					{
						cout << endl;
						obj_array[i]->print();
						cout << endl;
						header_printed = true;
					}

					// Выводим соответствующий объект
					switch (t)
					{
					case 0: cout << *obj_array[i]; break;
					case 1: cout << *dynamic_cast<Entrepreneur*>(obj_array[i]); break;
					case 2: cout << *dynamic_cast<Tourist*>(obj_array[i]); break;
					case 3: cout << *dynamic_cast<Businessman*>(obj_array[i]); break;
					}
				}
			}
			break;
		}
		case 6:
			is_running = false;
			break;
		}
	}

	// Освобождаем память
	for (int i = 0; i < arr_count; i++)
		delete obj_array[i];
}

void lab4_menu()
{
	Ring<Human> human_ring;
	Ring<Entrepreneur> entr_ring;
	Ring<Tourist> tourist_ring;
	Ring<Businessman> bm_ring;

	bool is_running = true;
	while (is_running)
	{
		cout << "\n      Choose a Ring" << endl;
		cout << "1. Ring<Human>;" << endl;
		cout << "2. Ring<Entrepreneur>;" << endl;
		cout << "3. Ring<Tourist>;" << endl;
		cout << "4. Ring<Businessman>;" << endl;
		cout << "5. Back." << endl;

		int choice;
		cout << "Your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1: 
			ring_menu(human_ring, "Human"); 
			break;
		case 2: 
			ring_menu(entr_ring, "Entrepreneur"); 
			break;
		case 3: 
			ring_menu(tourist_ring, "Tourist"); 
			break;
		case 4: 
			ring_menu(bm_ring, "Businessman"); 
			break;
		case 5: 
			is_running = false; 
			break;
		}
	}
}

template <typename T>
void ring_menu(Ring<T>& ring, const string& class_name)
{
	bool is_running = true;
	while (is_running)
	{
		cout << "\n         Ring<" << class_name << ">, elements: " << ring.get_size() << endl;
		cout << "1. Add an element;" << endl;
		cout << "2. Delete element;" << endl;
		cout << "3. Print the ring;" << endl;
		cout << "4. Find an element by surname;" << endl;
		cout << "5. Find an element by year;" << endl;
		cout << "6. Back." << endl;

		int choice;
		cout << "Your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			T new_obj;
			cin >> new_obj;
			ring.add_element(new_obj);

			cout << "Element added." << endl;
			break;
		}
		case 2:
		{
			if (ring.get_size() == 0)
			{
				cout << "Ring is empty." << endl;
				break;
			}

			ring.delete_element();
			cout << "Head element deleted." << endl;
			break;
		}
		case 3:
		{
			ring.print();
			break;
		}
		case 4:
		{
			string surname;
			cout << "Enter surname: ";
			getline(cin >> ws, surname);

			RingNode<T>* found = ring.find_by_surname(surname);
			if (found == nullptr)
			{
				cout << "Not found." << endl;
				break;
			}

			found->get_value().print();
			cout << endl;
			cout << found->get_value();
			break;
		}
		case 5:
		{
			int year;
			cout << "Enter year: ";
			cin >> year;

			RingNode<T>* found = ring.find_by_year(year);
			if (found == nullptr)
			{
				cout << "Not found." << endl;
				break;
			}

			found->get_value().print();
			cout << endl;
			cout << found->get_value();
			break;
		}
		case 6:
			is_running = false;
			break;
		}
	}
}