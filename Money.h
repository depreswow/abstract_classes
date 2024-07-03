#pragma once
#include "Pair.h"

class Money 
	: public Pair {
public:
	Money() = default;
	explicit Money(double in_number);

	void add(const Pair* in_pair) override;
	void substract(const Pair* in_pair) override;

	void multiply(const Pair* in_pair) override;
	void multiply(double in_number);

	void divide(const Pair* in_pair) override;
	void divide(double in_number);

	bool equal(const Pair* in_pair) const override;
	bool greater(const Pair* in_pair) const;
	bool lower(const Pair* in_pair) const;

	void print() const override;
};