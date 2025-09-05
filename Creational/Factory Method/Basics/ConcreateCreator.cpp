#include "ConcreateCreator.h"
#include "ConcreteProduct.h"

Product* ConcreateCreator::Create()
{
	return new ConcreteProduct{};
}
