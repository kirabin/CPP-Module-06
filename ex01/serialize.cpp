#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

std::string		get_random_string(int n) {
	std::string s;

	for (int i = 0; i < n; i++) {
		s += static_cast<char>(rand() % 26 + 'a');
	}
	return s;
}

void* serialize(void) {
	Data* data = new Data;

	data->s1 = get_random_string(8);
	data->n = rand() % 10;
	data->s2 = get_random_string(8);
	return reinterpret_cast<void*>(data);
}

Data* deserialize(void* raw) {
	return reinterpret_cast<Data*>(raw);
}

int main()
{
	srand(time(NULL));
	void *raw = serialize();
	Data *data = deserialize(raw);

	std::cout << data->s1 << std::endl;
	std::cout << data->n << std::endl;
	std::cout << data->s2 << std::endl;

	return 0;
}
