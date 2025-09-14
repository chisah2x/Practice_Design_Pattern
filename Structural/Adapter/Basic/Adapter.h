#pragma once
#include "Target.h"
#include "Adaptee.h"

class Adapter :
	public Target, public Adaptee
{
	//Adaptee m_Adaptee ;
public:
	void Request() override;
};

