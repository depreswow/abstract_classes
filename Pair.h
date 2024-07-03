#pragma once
#include <iostream>

class Pair {
private:
	int value_1;
	int value_2;
public:
	Pair() 
		: value_1(0), value_2(0) {};
	Pair(int in_value_1, int in_value_2) 
		: value_1(in_value_1), value_2(in_value_2) {};
	virtual ~Pair() {};
	
	virtual void add(const Pair* in_pair) = 0;
	virtual void substract(const Pair* in_pair) = 0;

	virtual void multiply(const Pair* in_pair) = 0;
	virtual void divide(const Pair* in_pair) = 0;

	virtual bool equal(const Pair* in_pair) const = 0;

	virtual void print() const = 0;

	int& get_1() {
		return value_1;
	}

	const int& get_1() const {
		return value_1;
	}

	int& get_2() {
		return value_2;
	}

	const int& get_2() const {
		return value_2;
	}
};