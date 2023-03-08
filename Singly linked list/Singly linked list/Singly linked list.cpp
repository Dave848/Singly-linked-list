#include "Node.h"
#include "SinglyLinkedList.h"
#include "Interface.h"
#include <vector>
#include <algorithm>

int main()
{
	int input = 0;
	Interface<int> interfaceInt;
	Interface<char> interfaceChar;
	Interface<std::string> interfaceString;

	std::cout << "1. Test for ints." << std::endl;
	std::cout << "2. Test for chars." << std::endl;
	std::cout << "3. Test for strings." << std::endl;

	while (std::cout << "Select option (1-3): " && !(std::cin >> input))
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Invalid input. Try again." << std::endl;
	}

	switch (input)
	{
	case 1:
		system("PAUSE");
		system("CLS");
		interfaceInt.show_interface();
		break;

	case 2:
		system("PAUSE");
		system("CLS");
		interfaceChar.show_interface();
		break;

	case 3:
		system("PAUSE");
		system("CLS");
		interfaceString.show_interface();
		break;
	default:
		std::cout << "Wrong value. Exiting." << std::endl;
	}

	// TEST ZASTĘPCZY
	std::vector<int> vec;
	for (int i = 0; i < 100; i++)
	{
		vec.push_back(i);
	}

	std::for_each(vec.begin(), vec.end(), [](int el) {std::cout << el; });
	std::cout << std::endl;
	std::transform(vec.begin(), vec.end(), vec.begin(), [](int el)
		{
			if (el % 2 == 0)
			{
				return el * el;
			}
			else
			{
				return el;
			}
		});
}

