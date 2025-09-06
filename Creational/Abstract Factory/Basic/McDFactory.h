#pragma once
#include "AbstractFactory.h"
class ConcreteFactory1 :
	public AbstractFactory
{

public:
	AbstractBurger* CreateProductA_Burger() override; //create burger from McDonald's
	AbstractGarlicBread* CreateProductB_GarlicBread() override; //create garlic bread from McDonald's
};

