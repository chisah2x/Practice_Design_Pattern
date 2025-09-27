#pragma once
#include "Flyweight.h"
class UnsharedConcreteFlyweight :
    public Flyweight
{
	int m_InternalState{} ;

public:
	UnsharedConcreteFlyweight(int mInternalState)
		: m_InternalState{mInternalState} {
	}

	void Operation(int extrinsic) override;
};

