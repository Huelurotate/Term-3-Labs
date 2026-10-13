#include "human.h"
#include "entrepreneur.h"
#include "tourist.h"
#include "businessman.h"

int main()
{
	bool is_running = true;
	while(is_running)
	{
		std::cout << "         Menu" << std::endl;
		std::cout << "1. Human object;" << std::endl;
		std::cout << "2. Entrepreneur object;" << std::endl;
		std::cout << "3. Tourist object;" << std::endl;
		std::cout << "4. Businessman object;" << std::endl;
		
		int choice;
		std::cout << "Your choice: ";

		switch(choice)
		{
			case 1:
				Human* new_human = new Human;
				std::cin >> new_human;
				obj_array[arr_count++] = human;
				std::cout << obj_array[arr_count];
				delete new_human;
			case 2:
				std::cin >> obj_array[arr_count++];
				std::cout << obj_array[arr_count]; 
			case 3:
				std::cin >> obj_array[arr_count++];
				std::cout << obj_array[arr_count]; 
			case 4:
				std::cin >> obj_array[arr_count++];
				std::cout << obj_array[arr_count]; 
		}
	}

	return 0;
}