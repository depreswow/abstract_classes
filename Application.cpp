#include "Application.h"
#define COMPLEX 1
#define MONEY 2


Application::Application() 
	: pair_1(nullptr), pair_2(nullptr) {}

Application::~Application() {
	if (pair_1 != nullptr)
		delete pair_1;
	if (pair_2 != nullptr)
		delete pair_2;
}

void Application::Run() {
	int option;
	do {
		std::cout << R"(Choose:
	1. Work with Complex
	2. Work with Money
	3. Exit)" << std::endl;
		do
			std::cin >> option;
		while (option < 1 || option > 3);
		switch (option) {
		case (COMPLEX):
			Run_Complex();
			break;
		case (MONEY):
			Run_Money();
			break;
		}
	} while (option != 3);
}

void Application::Run_Complex() {
	pair_1 = new Complex;
	pair_2 = new Complex;
	int option;
	do {
		std::cout << R"(Choose:
	1. Enter complex 1
	2. Enter complex 2
	3. Add complex 2 to complex 1
	4. Substract complex 2 from complex 1
	5. Multiply complex 1 by complex 2
	6. Divide complex 1 by complex 2
	7. complex 1 == complex 2
	8. Conjugate with complex 1
	9. Exit)" << std::endl;
		do
			std::cin >> option;
		while (option < 1 || option > 9);
		switch (option) {
		case (1):
			std::cout << "Enter value 1:" << std::endl;
			std::cin >> pair_1->get_1();
			std::cout << "Enter value 2:" << std::endl;
			std::cin >> pair_1->get_2();
			break;
		case (2):
			std::cout << "Enter value 1:" << std::endl;
			std::cin >> pair_2->get_1();
			std::cout << "Enter value 2:" << std::endl;
			std::cin >> pair_2->get_2();
			break;
		case (3):
			pair_1->add(pair_2);
			break;
		case (4):
			pair_1->substract(pair_2);
			break;
		case (5):
			pair_1->multiply(pair_2);
			break;
		case (6):
			pair_1->divide(pair_2);
			break;
		case (7):
			std::cout << pair_1->equal(pair_2) << std::endl;
			break;
		case (8):
			dynamic_cast<const Complex*>(pair_1)->conj().print();
			break;
		}
		std::cout << "Complex 1: ";
		pair_1->print();
		std::cout << std::endl << "Complex 2: ";
		pair_2->print();
		std::cout << std::endl;
	} while (option != 9);
	delete pair_1;
	pair_1 = nullptr;
	delete pair_2;
	pair_2 = nullptr;
}

void Application::Run_Money() {
	pair_1 = new Money;
	pair_2 = new Money;
	int option;
	do {
		std::cout << R"(Choose:
	1. Enter money 1
	2. Enter money 2
	3. Add money 2 to money 1
	4. Substract money 2 from money 1
	5. Multiply money 1 by money 2
	6. Divide money 1 by money 2
	7. money 1 == money 2
	8. money 1 > money 2
	9. money 1 < money 2
	10. Exit)" << std::endl;
		do
			std::cin >> option;
		while (option < 1 || option > 10);
		switch (option) {
		case (1):
			std::cout << "Enter value 1:" << std::endl;
			std::cin >> pair_1->get_1();
			std::cout << "Enter value 2:" << std::endl;
			std::cin >> pair_1->get_2();
			break;
		case (2):
			std::cout << "Enter value 1:" << std::endl;
			std::cin >> pair_2->get_1();
			std::cout << "Enter value 2:" << std::endl;
			std::cin >> pair_2->get_2();
			break;
		case (3):
			pair_1->add(pair_2);
			break;
		case (4):
			pair_1->substract(pair_2);
			break;
		case (5):
			pair_1->multiply(pair_2);
			break;
		case (6):
			pair_1->divide(pair_2);
			break;
		case (7):
			std::cout << pair_1->equal(pair_2) << std::endl;
			break;
		case (8):
			std::cout << dynamic_cast<const Money*>(pair_1)->greater(pair_2) << std::endl;;
			break;
		case (9):
			std::cout << dynamic_cast<const Money*>(pair_1)->lower(pair_2) << std::endl;;
			break;
		}
		std::cout << "Money 1: ";
		pair_1->print();
		std::cout << std::endl << "Money 2: ";
		pair_2->print();
		std::cout << std::endl;
	} while (option != 10);
	delete pair_1;
	pair_1 = nullptr;
	delete pair_2;
	pair_2 = nullptr;
}