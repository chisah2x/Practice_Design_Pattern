#include "BurgerKingFactory.h"
#include "BurgerKing.h"

AbstractBurger* ConcreteFactory2::CreateProductA_Burger() {
	return new CreateBurger2{} ;
}

AbstractGarlicBread* ConcreteFactory2::CreateProductB_GarlicBread() {
	return new CreateGarlicBread2{} ;
}
