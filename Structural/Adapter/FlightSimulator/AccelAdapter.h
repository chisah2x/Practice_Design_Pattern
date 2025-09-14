#pragma once
#include "Accelerometer.h"
#include "Input.h"
class AccelAdapter :
	public Input
{
	Accelerometer m_Accel ;
public:
	bool Up() override;
	bool Down() override;
	bool Left() override;
	bool Right() override;
};

