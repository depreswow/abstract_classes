#include "Complex.h"

void Complex::add(const Pair* in_pair) {
	get_1() += in_pair->get_1();
	get_2() += in_pair->get_2();
}

void Complex::substract(const Pair* in_pair) {
	get_1() -= in_pair->get_1();
	get_2() -= in_pair->get_2();
}

void Complex::multiply(const Pair* in_pair) {
	get_1() = get_1() * in_pair->get_1() - get_2() * in_pair->get_2();
	get_2() = get_1() * in_pair->get_2() + get_2() * in_pair->get_1();
}

void Complex::divide(const Pair* in_pair) {
	get_1() = (get_1() * in_pair->get_1() + get_2() * in_pair->get_2()) / (in_pair->get_1() * in_pair->get_1() + in_pair->get_2() * in_pair->get_2());
	get_2() = (get_2() * in_pair->get_1() - get_1() * in_pair->get_2()) / (in_pair->get_1() * in_pair->get_1() + in_pair->get_2() * in_pair->get_2());
}

bool Complex::equal(const Pair* in_pair) const {
	if (get_1() == in_pair->get_1() && get_2() == in_pair->get_2())
		return true;
	return false;
}

void Complex::print() const {
	std::cout << "(" << get_1() << ", " << get_2() << ")" << std::endl;
}

Complex Complex::conj() const {
	Complex buffer;
	buffer.get_1() = get_1();
	buffer.get_2() = -get_2();
	return buffer;
}
