#include<iostream>
#include<string>
#include<cstdlib>

int main()	{
	std::string name;
	std::int8_t os; // 1 means windows, 0 means unix
	std::cout << "todolist-cli v1" << std::endl;
	std::cout << "Please enter a name for this list:";
	std::cin >> name;
	// clearing terminal and defining os
	int unix = system("clear");
	if (unix != 0) {
		int windows = system("cls");
		if (windows != 0) {
			std::cerr << "Error clearing terminal, please switch to a system that supports the clear or the cls function." << std::endl;
			return 1;
		}
		else {
			os = 1;
		}
	}
	else {
		os = 0;
	}

	std::cout << "List:" << name << std::endl;
	while (true) {

	}
	return 0;
}
