#pragma once
#include <iostream>
#include "Complex.h"
#include "Money.h"

class Application {
private:
	Pair* pair_1;
	Pair* pair_2;
public:
	Application();
	~Application();

	void Run();
	void Run_Complex();
	void Run_Money();
};