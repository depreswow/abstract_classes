#pragma once
#include "Pair.h"

class Complex 
	: public Pair {
public:

	void add(const Pair* in_pair) override;
	void substract(const Pair* in_pair) override;

	void multiply(const Pair* in_pair) override;
	void divide(const Pair* in_pair) override;

	bool equal(const Pair* in_pair) const override;

	void print() const override;

	Complex conj() const;
};