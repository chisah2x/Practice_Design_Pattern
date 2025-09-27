#pragma once
#include "Flyweight.h"
class ConcreteFlyweight :
    public Flyweight
{
	int *m_pIntrinisicState{} ;
public:

	ConcreteFlyweight(int* mPIntrinisicState)
		: m_pIntrinisicState{mPIntrinisicState} {
	}

	void Operation(int extrinsic) override;
};

