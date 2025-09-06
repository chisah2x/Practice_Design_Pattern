#include "McDFactory.h"
#include "McD.h"

AbstractBurger* ConcreteFactory1::CreateProductA_Burger() {
	return new CreateBurger1{} ;
}

AbstractGarlicBread* ConcreteFactory1::CreateProductB_GarlicBread() {
	return new CreateGarlicBread1{} ;
}
