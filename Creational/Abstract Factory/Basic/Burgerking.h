#pragma once
#include <iostream>
#include "AbstractGarlicBread.h"
#include "AbstractBurger.h"

//Let's say Burger King
class CreateBurger2 : public AbstractBurger {

public:
	void CreateBurger() override {
		std::cout << "[BurgerKing] Product A: Burger\n" ;
	}
};

class CreateGarlicBread2 : public AbstractGarlicBread {

public:
	void CreateGarlicBread() override {
		std::cout << "[BurgerKing] Product B: Garlic Bread\n" ;
	}
};