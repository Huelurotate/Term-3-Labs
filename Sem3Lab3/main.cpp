#include "human.h"
#include "entrepreneur.h"
#include "tourist.h"
#include "businessman.h"

int main()
{
	Human* obj_array[100];
	int arr_count = 0;

	bool is_running = true;
	while(is_running)
	{
		std::cout << "         Menu" << std::endl;
		std::cout << "1. Add a Human object;" << std::endl;
		std::cout << "2. Add an Entrepreneur object;" << std::endl;
		std::cout << "3. Add a Tourist object;" << std::endl;
		std::cout << "4. Add a Businessman object;" << std::endl;
		std::cout << "5. Print all objects;" << std::endl;
		std::cout << "6. Exit." << std::endl;
		
		int choice;
		std::cout << "Your choice: ";
		std::cin >> choice;

		switch(choice)
		{
			case 1:
			{
				Human* new_human = new Human;
				std::cin >> *new_human;
				obj_array[arr_count++] = new_human;
				std::cout << *obj_array[arr_count - 1] << std::endl;
				break;
			}
			case 2:
			{
				Entrepreneur* new_entr = new Entrepreneur;
				std::cin >> *new_entr;
				obj_array[arr_count++] = new_entr;
				std::cout << *obj_array[arr_count - 1] << std::endl;
				break;
			}
			case 3:
			{
				Tourist* new_tourist = new Tourist;
				std::cin >> *new_tourist;
				obj_array[arr_count++] = new_tourist;
				std::cout << *obj_array[arr_count - 1] << std::endl;
				break;
			}
			case 4:
			{
				Businessman* new_bm = new Businessman;
				std::cin >> *new_bm;
				obj_array[arr_count++] = new_bm;
				std::cout << *obj_array[arr_count - 1] << std::endl;
				break;
			}
			case 5:
			{
				if (arr_count == 0)
				{
					std::cout << "No objects yet." << std::endl;
					break;
				}

				for (int i = 0; i < arr_count; i++)
				{
					std::cout << *obj_array[i];
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