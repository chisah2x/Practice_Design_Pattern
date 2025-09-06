#include "AbstractBurger.h"
#include "AbstractGarlicBread.h"
#include "AbstractFactory.h"
#include "McDFactory.h"
#include "BurgerKingFactory.h"

void UsePattern(AbstractFactory *pFactory) {
	AbstractBurger *pA = pFactory->CreateProductA_Burger()  ;
	AbstractGarlicBread *pB = pFactory->CreateProductB_GarlicBread() ;

	pA->CreateBurger() ;
	pB->CreateGarlicBread() ;

	delete pA ;
	delete pB ;
}

int main() {
	/*AbstractBurger* pA = new CreateBurger1();
	AbstractGarlicBread* pB = new CreateGarlicBread1();*/

	AbstractFactory* pFactory = new ConcreteFactory1{}; //McDonald's factory
	UsePattern(pFactory);

	pFactory = new ConcreteFactory2{} ; //BurgerKing factory
	UsePattern(pFactory) ;
	delete pFactory ;
}
