#pragma once
#include "AbstractFactory.h"
class ConcreteFactory2 :
	public AbstractFactory
{

public:
	AbstractBurger* CreateProductA_Burger() override; //create burger from BurgerKing
	AbstractGarlicBread* CreateProductB_GarlicBread() override; //create garlic bread from BurgerKing
};

