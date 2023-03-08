#ifndef _INTERFACE
#define _INTERFACE

#include "SinglyLinkedList.h"
#include <iomanip>
#include <stdlib.h>

template<typename T>
class Interface
{
	SinglyLinkedList<T> list;
public:
	void show_interface()
	{
		bool selected0 = false;
		unsigned int option = 0;
		T element;

		while (!selected0)
		{
			std::cout << std::setfill(' ') << std::setw(37) << "Singly linked list test." << std::endl;
			std::cout << "#################################################" << std::endl;
			std::cout << "1. Display list." << std::endl;
			std::cout << "2. Add element to list." << std::endl;
			std::cout << "3. Remove element from list." << std::endl;
			std::cout << "4. Check if element is in list." << std::endl;
			std::cout << "5. Sort list." << std::endl;
			std::cout << "6. Serialize data from list." << std::endl;
			std::cout << "7. Get data by index." << std::endl;
			std::cout << "0. Leave testing." << std::endl;
			std::cout << "#################################################" << std::endl;

			while (std::cout << "Choose option (0-7): " && !(std::cin >> option))
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Invalid input. Try again." << std::endl;
			}

			switch (option)
			{
			case 0:
				selected0 = true;
				break;

			case 1:
				if (list.is_empty())
				{
					std::cout << "List is empty!" << std::endl;
					break;
				}
				std::cout << "List: ";
				list.show_list();
				break;

			case 2:
				add_element();
				break;

			case 3:
				remove_element();
				break;

			case 4:
				while (std::cout << "Type in element: " && !(std::cin >> element))
				{
					std::cin.clear();
					std::cin.ignore();
					std::cout << "Invalid input. Try again." << std::endl;
				}

				if(list.search(element))
				{
					std::cout << "This element is in the list." << std::endl;
				}
				else
				{
					std::cout << "This element is not in the list." << std::endl;
				}

				break;

			case 5:
				if (list.is_empty())
				{
					std::cout << "List is empty!" << std::endl;
					break;
				}
				list.sort();
				std::cout << "List is sorted!";
				break;

			case 6:
				if (list.is_empty())
				{
					std::cout << "List is empty!" << std::endl;
					break;
				}
				list.serialize();
				std::cout << "Serialized successfully." <<std::endl;
				break;

			case 7:
				if (list.is_empty())
				{
					std::cout << "List is empty!" << std::endl;
					break;
				}
				get_by_index();
				break;
				
			default:
				std::cout << "Wrong value, try again." << std::endl;
				break;
			}

			std::cout << std::endl;
			system("PAUSE");
			system("CLS");
		}
	}

	void add_element()
	{
		unsigned int option = 0;
		T element;

		std::cout << "1. Insert to front." << std::endl;
		std::cout << "2. Insert to back." << std::endl;
		std::cout << "0. Go back." << std::endl;

		while (std::cout << "Choose option (0-2): " && !(std::cin >> option))
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Invalid input. Try again." << std::endl;
		}

		switch (option)
		{
		case 0:
			return;

		case 1:
			while (std::cout << "Type in element: " && !(std::cin >> element))
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Invalid input. Try again." << std::endl;
			}
			list.insert_front(element);
			return;

		case 2:
			while (std::cout << "Type in element: " && !(std::cin >> element)) 
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Invalid input. Try again." << std::endl;
			}
			list.insert_back(element);
			return;

		default:
			std::cout << "Invalid input. Try again." << std::endl;
			add_element();
			break;
		}
	}

	void remove_element()
	{
		unsigned int option = 0;
		T element;

		if(list.is_empty())
		{
			std::cout << "List is empty!" << std::endl;
			return;
		}

		std::cout << "1. Pop element from back." << std::endl;
		std::cout << "2. Pop element from front." << std::endl;
		std::cout << "3. Remove element by its name." << std::endl;
		std::cout << "0. Go back." << std::endl;

		std::cout << "Choose option (0-2): ";
		std::cin >> option;

		switch (option)
		{
		case 0:
			return;

		case 1:
			std::cout << "Removed element: " << list.pop_back()->data << std::endl;
			return;

		case 2:
			std::cout << "Removed element: " << list.pop_front()->data << std::endl;
			return;

		case 3:
			while (std::cout << "Type in element to remove: " && !(std::cin >> element)) 
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Invalid input. Try again." << std::endl;
			}

			if(!list.search(element))
			{
				std::cout << "This element is not in the list!" << std::endl;
				return;
			}

			list.remove(element);
			return;

		default:
			std::cout << "Wrong value, try again." << std::endl;
			std::cout << "#################################################" << std::endl;

			remove_element();
			break;
		}
	}

	void get_by_index()
	{
		int index = 0;
		while (std::cout << "Enter index: " && !(std::cin >> index)) 
		{
			std::cin.clear(); 
			std::cin.ignore(); 
			std::cout << "Invalid input. Try again." << std::endl;
		}

		if (list.good_index(index))
		{
			std::cout << "List[" << index << "] = " << list[index] << std::endl;
		}
		else
		{
			std::cout << "Wrong index value. Try again." << std::endl;
			get_by_index();
		}
	}

};

#endif