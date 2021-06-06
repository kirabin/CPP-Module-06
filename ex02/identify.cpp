#include <iostream>
#include <string>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
	int choice = rand() % 3;

	if (choice == 0)
		return new A;
	else if (choice == 1)
		return new B;
	else
		return new C;
}

void identify_from_pointer(Base * p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Doesn't belong here" << std::endl;
}

void identify_from_reference(Base& p) {

	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	} catch (...) {}

	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	} catch (...) {}

	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	} catch (...) {}
	std::cout << "Doesn't belong here" << std::endl;
}

int main()
{
	void *nobody = NULL;
	srand(time(NULL));
	Base* some_base = generate();
	Base& ref = *some_base;
	identify_from_pointer(some_base);
	identify_from_reference(ref);
	identify_from_pointer(reinterpret_cast<Base *>(nobody));
	return 0;
}
