#include <typeinfo>

#include "human.h"
#include "entrepreneur.h"
#include "tourist.h"
#include "businessman.h"

int main()
{
	Human* obj_array[100];
	int arr_count = 0;

	bool is_running = true;
	while (is_running)
	{
		cout << "\n         Menu" << endl;
		cout << "1. Add a Human object;" << endl;
		cout << "2. Add an Entrepreneur object;" << endl;
		cout << "3. Add a Tourist object;" << endl;
		cout << "4. Add a Businessman object;" << endl;
		cout << "5. Print all objects;" << endl;
		cout << "6. Exit." << endl;

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
			case 5:
			{
				if (arr_count == 0)
				{
					cout << "No objects yet." << endl;
					break;
				}

				const type_info* types[4] = { &typeid(Human), &typeid(Entrepreneur),
												   &typeid(Tourist), &typeid(Businessman) };

				for (int t = 0; t < 4; t++)
				{
					bool header_printed = false;

					for (int i = 0; i < arr_count; i++)
					{
						if (typeid(*obj_array[i]) != *types[t])
							continue;

						if (!header_printed)
						{
							cout << endl;
							obj_array[i]->print();
							cout << endl;
							header_printed = true;
						}

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

	for (int i = 0; i < arr_count; i++)
		delete obj_array[i];

	return 0;
}
