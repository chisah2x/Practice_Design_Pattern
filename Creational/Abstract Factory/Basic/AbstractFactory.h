#pragma once
class AbstractBurger ;
class AbstractGarlicBread ;
class AbstractFactory
{
public:
	virtual AbstractBurger * CreateProductA_Burger() = 0 ;//create burger
	virtual AbstractGarlicBread * CreateProductB_GarlicBread() = 0 ;//create garlic bread
	virtual ~AbstractFactory()=default ;
};

