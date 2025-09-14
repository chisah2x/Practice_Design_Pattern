#pragma once
#include <random>

class Accelerometer
{
	std::default_random_engine m_Engine{999} ;
public:
	double GetHorizontalAxis() ;
	double GetVerticalAxis() ;
};

