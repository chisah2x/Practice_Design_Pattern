#include "Accelerometer.h"

#include <iostream>

double Accelerometer::GetHorizontalAxis() {
	std::uniform_int_distribution<> dist{-10, 10} ;
	auto value = dist(m_Engine) ;
	std::cout << "[Horizontal] " << value << std::endl; 
	return value ;
}

double Accelerometer::GetVerticalAxis() {
	std::uniform_int_distribution<> dist{-10, 10} ;
	auto value = dist(m_Engine) ;
	std::cout << "[Vertical] " << value << std::endl; 
	return value ;
}
