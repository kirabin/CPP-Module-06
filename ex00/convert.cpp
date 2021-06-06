#include <iostream>
#include <iomanip>

void	acuire_literal(std::string& str) {
	char c;
	int i;
	float f;
	double d;
	bool is_impossible_int = false;
	size_t len;

	// Integer
	try {
		i = std::stoi(str, &len);
		if (str.length() == len) {
			std::cout << "It's integer."<< std::endl << std::endl;
			if (i < -128 || i > 127)
				std::cout << "char: impossible" << std::endl;
			else if (32 <= static_cast<char>(i) && static_cast<char>(i) <= 127)
				std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
			else
				std::cout << "char: Non-displayable" << std::endl;
			std::cout << "int: " << static_cast<int>(i) << std::endl;
			std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(i) << "f" << std::endl;
			std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(i) << std::endl;
			return ;
		}
	} catch (std::exception& e) {
		is_impossible_int = true;
		// std::cout << e.what() << std::endl;
	}

	// Double
	try {
		d = std::stod(str, &len);
		if (str.length() == len) {
			std::cout << "It's double or overflowed integer." << std::endl << std::endl;
			if (d < -128 || d > 127)
				std::cout << "char: impossible" << std::endl;
			else if (32 <= static_cast<char>(d) && static_cast<char>(d) <= 127)
				std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
			else
				std::cout << "char: Non-displayable" << std::endl;
			if (is_impossible_int) {
				std::cout << "int: impossible" << std::endl;
			} else {
				std::cout << "int: " << static_cast<int>(d) << std::endl;
			}
			if (d < std::numeric_limits<float>::min() || std::numeric_limits<float>::max() < d) {
				std::cout << "float: impossible" << std::endl;
			} else {
				std::cout << std::showpoint << "float: " << static_cast<float>(d) << "f" << std::endl;
			}
			std::cout << std::showpoint << "double: " << static_cast<double>(d) << std::endl;
			return ;
		}
	} catch (std::exception& e) {
		// std::cout << e.what() << std::endl;
	}

	// Float
	// TODO: impossible char in case of nan etc.
	try {
		f = std::stof(str, &len);
		if (str.length() == len || (str.length() == len + 1 && str[str.length() - 1] == 'f')) {
			std::cout << "It's float." << std::endl << std::endl;
			if (f < -128 || f > 127)
				std::cout << "char: impossible" << std::endl;
			else if (32 <= static_cast<char>(f) && static_cast<char>(f) <= 127)
				std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
			else
				std::cout << "char: Non-displayable" << std::endl;
			if (is_impossible_int) {
				std::cout << "int: impossible" << std::endl;
			} else {
				std::cout << "int: " << static_cast<int>(f) << std::endl;
			}
			std::cout << std::showpoint << "float: " << static_cast<float>(f) << "f" << std::endl;
			std::cout << std::showpoint << "double: " << static_cast<double>(f) << std::endl;
			return ;
		}
	} catch (std::exception& e) {
		// std::cout << e.what() << std::endl;
	}

	// Char
	if (str.length() == 1) {
		std::cout << "It's char."<< std::endl << std::endl;
		c = str[0];
		if (32 <= static_cast<char>(c) && static_cast<char>(c) <= 127)
			std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
		else
			std::cout << "char: Non-displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(c) << std::endl;
		return ;
	}

	std::cout << "No conversion available" << std::endl;
}

int main(int argc, char** argv)
{
	if (argc == 2) {
		std::string input = argv[1];
		acuire_literal(input);
	} else if (argc == 1) {
		std::cerr << "Error: Not enough arguments" << std::endl;
	} else {
		std::cerr << "Error: Too many arguments" << std::endl;
	}
	return 0;
}
