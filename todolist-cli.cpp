#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>

class ExitCmd {
	public:
		void execute(int8_t os, int8_t &running) {
			if (os == 1) {
				system("cls");
			}
			else {
				system("clear");
			}
			std::cout << "Exiting" << std::endl;
			running = 0;
		}
};

class HelpCmd {
	public:
		void execute() {
			std::cout << "Commands:" << std::endl;
			std::cout << "exit -- Exits the program" << std::endl;
			std::cout << "help -- Displays this message" << std::endl;
			std::cout << "clear -- Clears the screen except the title" << std::endl;
			std::cout << "list -- Lists the current list" << std::endl;
			std::cout << "add -- Add an item to the list" << std::endl;
			std::cout << "remove -- Remove an item from the list";
			std::cout << "done -- Marks the specified item as done on the list" << std::endl;
		}
};

class ClearCmd {
public:
	void execute(int8_t os, std::string name) {
		if (os == 1) {
			system("cls");
		}
		else {
			system("clear");
		}
		std::cout << "List: " << name << std::endl;
	}
};


int main()	{
	std::string name;
	std::int8_t os; // 1 means windows, 0 means unix
	std::int8_t running; // 1 means running, 0 means stopped

	running = 1;
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

	std::cout << "List: " << name << std::endl;
	ExitCmd exit;
	ClearCmd clear;
	HelpCmd help;
	std::string cmd_input;
	std::vector<std::string> list = {};
	std::cout << "todolist-cli -- Type help for a list of commands." << std::endl;
	while (running == 1) {
		cmd_input = "";
		std::cout << "todolist-cli> ";
		std::cin >> cmd_input;
		switch (cmd_input[0]) {
			case 'e':
				exit.execute(os, running);
				break;
			case 'h':
				help.execute();
				break;
			case 'c':
				clear.execute(os, name);
				break;
			default:
				std::cout << "Unknown command, type help for a list of commands." << std::endl;
		}
	}
	return 0;
}
