#include "ConcreteFlyweight.h"

#include <iostream>

void ConcreteFlyweight::Operation(int extrinsic) {
	std::cout << "Intrinsic state:" << *m_pIntrinisicState << std::endl;
	std::cout << "Extrinsic state:" << extrinsic << std::endl; 
}
