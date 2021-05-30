#include <iostream>

void*	acuire_literal(std::string& str) {
	char* c = new char;
	int* i = new int;
	float* f = new float;
	double* d = new double;
	size_t len;

	try {
		*f = std::stof(str, &len);
		if (str.length() == len)
			return f;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void convert_to_char(std::string& str) {
	std::cout << "char: ";
	// std::cout << static_cast<char>(str);
	std::cout << std::endl;
}

void convert_to_int(std::string& str) {
	std::cout << "int: ";
	try {
		std::cout << std::stoi(str);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void convert_to_float(std::string& str) {
	std::cout << "float: ";
	std::cout << std::endl;
}

void convert_to_double(std::string& str) {
	std::cout << "double: ";
	std::cout << std::endl;
}

int main(int argc, char** argv)
{
	if (argc == 2) {
		std::string input = argv[1];

		void *literal = acuire_literal(input);
		std::cout << literal << std::endl;

		convert_to_char(input);
		convert_to_int(input);
		convert_to_float(input);
		convert_to_double(input);
	} else if (argc == 1) {
		std::cerr << "Error: Not enough arguments" << std::endl;
	} else {
		std::cerr << "Error: Too many arguments" << std::endl;
	}
	return 0;
}
