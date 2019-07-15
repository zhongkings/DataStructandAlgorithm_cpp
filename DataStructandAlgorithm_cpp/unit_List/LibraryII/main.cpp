#include "libData.h"
#include <iostream>
#include <string>
//声明出来，要不然main找不到这些函数
void includeBook();
void checkOutBook();
void returnBook();

int menu(char **argv) {
	std::string option;
	std::cout << "Apple Path --> " << *argv << std::endl;
	std::cout << "Enter one of the following options(#menu go back menu): \n";
	std::cout << "1. Include a book in the catalog\n";
	std::cout << "2. Checkout a book \n";
	std::cout << "3. Return a book \n";
	std::cout << "4. Status \n";
	std::cout << "5. Exit " << std::endl;
	std::cout << "Input(Number): ";
	std::getline(std::cin, option);

	return option[0];
}

int main(int argc, char **argv) {
	while (true)
	{
		system("cls");
		switch (menu(argv))
		{
		case '1': includeBook(); break;
		case '2': checkOutBook(); break;
		case '3': returnBook(); break;
		case '4': libData::status(); getchar(); break;
		case '5': return 0;
		default: system("cls");
		}
	}

	return 0;
}