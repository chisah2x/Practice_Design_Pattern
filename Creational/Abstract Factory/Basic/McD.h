#pragma once
#include "AbstractBurger.h"
#include <iostream>
#include "AbstractGarlicBread.h"

//Let's say McDonald's
class CreateBurger1 : public AbstractBurger {

public:
	void CreateBurger() override {
		std::cout << "[McDonald's] Product A: Burger\n" ;
	}
};

class CreateGarlicBread1 : public AbstractGarlicBread {

public:
	void CreateGarlicBread() override {
		std::cout << "[McDonald's] Product B: Garlic Bread\n" ;
	}
};
