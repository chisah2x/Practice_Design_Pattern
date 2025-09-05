#pragma once
#include "Product.h"
class ConcreteProduct :
    public Product
{
public:

    // Inherited via Product
    void Operation() override;
};

