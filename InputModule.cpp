#include "InputModule.h"
#include <functional>

std::string InputModule::trimFront(std::string& str) {
	str.erase(str.begin(), 
		std::find_if(
			str.begin(), str.end(),
			std::not1(
				std::ptr_fun<int, int>(std::isspace)
			)
		)
	);
	return str;
}

std::string InputModule::trimBack(std::string& str) {
	str.erase(std::find_if(
				str.rbegin(), 
				str.rend(),
				std::not1(std::ptr_fun<int, int>(std::isspace))
			).base(),
		str.end()
	);

	return str;
}

std::string InputModule::trim(std::string& str) {
	std::string result = trimFront(str);
	return trimBack(result);
}

int InputModule::getIntegerInput(std::string prompt){
	bool valid = false;
	int input = 0;

	do {
		try {
			std::cout << prompt;
			std::cin >> input;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(ignoreSize, '\n');
				throw std::string("The input should be integer value. ");
			}
			std::cin.ignore(ignoreSize, '\n');
			valid = true;
		}
		catch (std::string& msg) {
			std::cout << "Invalid input : " << msg << std::endl;
		}
	} while (!valid);

	return input;
}

char InputModule::getCharInput(std::string prompt) {
	bool valid = false;
	char input = '\0';

	do {
		try {
			std::cout << prompt;
			std::cin >> input;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(ignoreSize, '\n');
				throw std::string("The input should be character value. ");
			}
			std::cin.ignore(ignoreSize, '\n');
			valid = true;
		}
		catch (std::string& msg) {
			std::cout << "Invalid input : " << msg << std::endl;
		}
	} while (!valid);

	return input;
}

std::string InputModule::getStringInput(std::string prompt) {
	bool valid = false;
	std::string input("");

	do {
		try {
			std::cout << prompt;
			std::getline(std::cin, input);
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(ignoreSize, '\n');
				throw std::string("Failed to catch input");
			}
			if (trim(input).length() == 0)
				throw std::string("Input should contain at least one character.");
			valid = true;
		}
		catch (std::string& msg) {
			std::cout << "Invalid input : " << msg << std::endl;
		}
	} while (!valid);

	return input;
}

double InputModule::getDoubleInput(std::string prompt) {
	bool valid = false;
	double input = 0.0;

	do {
		try {
			std::cout << prompt;
			std::cin >> input;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(ignoreSize, '\n');
				throw std::string("The input should be double value. ");
			}
			std::cin.ignore(ignoreSize, '\n');
			valid = true;
		}
		catch (std::string& msg) {
			std::cout << "Invalid input : " << msg << std::endl;
		}
	} while (!valid);

	return input;
}

std::queue<std::string> InputModule::split_string(std::string input,const char delimiter) {
	std::queue<std::string> part;
	int start = 0;
	int end = 0;
	const int length = input.length();

	while (start < length) {
		end = input.find(delimiter, start);
		if (end <= start) { part.push(input.substr(start, length-start)); start = length; }
		else {
			part.push(input.substr(start, end - start));
			start = end + 1;
		}
	}

	return part;
}