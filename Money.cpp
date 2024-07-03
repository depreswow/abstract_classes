#include "Money.h"

//в первой и третьей части по-разному считаются операции для Money, в целом большой разницы быть не должно

Money::Money(double in_number) {
	get_1() = (int)in_number;
	get_2() = (int)((in_number - (double)get_1()) * 100);
}

void Money::add(const Pair* in_pair) {
	get_2() += in_pair->get_2();
	get_1() += in_pair->get_1() + (get_2() / 100);
	get_2() %= 100;
}

void Money::substract(const Pair* in_pair) {
	get_2() -= in_pair->get_2();
	if (get_2() < 0) {
		get_2() += 100;
		get_1()--;
	}
	get_1() -= in_pair->get_1();
}

void Money::multiply(const Pair* in_pair) {
	double buffer = (double)in_pair->get_1() + ((double)in_pair->get_2() / 100);
	this->multiply(buffer);
}

void Money::multiply(double in_number) {
	double buffer = get_1() * in_number;
	get_1() = (int)buffer;
	get_2() = (((double)get_2() / 100) * in_number + (buffer - get_1())) * 100;
}

void Money::divide(const Pair* in_pair) {
	double buffer = (double)in_pair->get_1() + ((double)in_pair->get_2() / 100);
	this->divide(buffer);
}

void Money::divide(double in_number) {
	this->multiply(1 / in_number);
}

bool Money::equal(const Pair* in_pair) const {
	if (get_1() == in_pair->get_1() && get_2() == in_pair->get_2())
		return true;
	return false;
}

bool Money::greater(const Pair* in_pair) const {
	if (get_1() > in_pair->get_1())
		return true;
	if (get_1() == in_pair->get_1() && get_2() > in_pair->get_2())
		return true;
	return false;
}

bool Money::lower(const Pair* in_pair) const {
	if (get_1() < in_pair->get_1())
		return true;
	if (get_1() == in_pair->get_1() && get_2() < in_pair->get_2())
		return true;
	return false;
}

void Money::print() const {
	std::cout << get_1() << ", " << get_2() << std::endl;
}