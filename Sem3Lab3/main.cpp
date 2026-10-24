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
		std::cout << "\n         Menu" << std::endl;
		std::cout << "1. Add a Human object;" << std::endl;
		std::cout << "2. Add an Entrepreneur object;" << std::endl;
		std::cout << "3. Add a Tourist object;" << std::endl;
		std::cout << "4. Add a Businessman object;" << std::endl;
		std::cout << "5. Print all objects;" << std::endl;
		std::cout << "6. Exit." << std::endl;

		int choice;
		std::cout << "Your choice: ";
		std::cin >> choice;

		if (choice >= 1 && choice <= 4 && arr_count >= 100)
		{
			std::cout << "Array is full." << std::endl;
			continue;
		}

		switch (choice)
		{
			case 1:
			{
				Human* new_human = new Human;
				std::cin >> *new_human;
				obj_array[arr_count++] = new_human;

				new_human->print();
				std::cout << *new_human;
				break;
			}
			case 2:
			{
				Entrepreneur* new_entr = new Entrepreneur;
				std::cin >> *new_entr;
				obj_array[arr_count++] = new_entr;

				new_entr->print();
				std::cout << *new_entr;
				break;
			}
			case 3:
			{
				Tourist* new_tourist = new Tourist;
				std::cin >> *new_tourist;
				obj_array[arr_count++] = new_tourist;

				new_tourist->print();
				std::cout << *new_tourist;
				break;
			}
			case 4:
			{
				Businessman* new_bm = new Businessman;
				std::cin >> *new_bm;
				obj_array[arr_count++] = new_bm;

				new_bm->print();
				std::cout << *new_bm;
				break;
			}
			case 5:
			{
				if (arr_count == 0)
				{
					std::cout << "No objects yet." << std::endl;
					break;
				}

				const std::type_info* types[4] = { &typeid(Human), &typeid(Entrepreneur),
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
							std::cout << std::endl;
							obj_array[i]->print();
							std::cout << std::endl;
							header_printed = true;
						}

						switch (t)
						{
							case 0: std::cout << *obj_array[i]; break;
							case 1: std::cout << *dynamic_cast<Entrepreneur*>(obj_array[i]); break;
							case 2: std::cout << *dynamic_cast<Tourist*>(obj_array[i]); break;
							case 3: std::cout << *dynamic_cast<Businessman*>(obj_array[i]); break;
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
