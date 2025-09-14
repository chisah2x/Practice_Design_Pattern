#include "Accelerometer.h"

#include <iostream>

double Accelerometer::GetHorizontalAxis() {
	auto init_values = Initialize() ;
	std::uniform_int_distribution<> dist{init_values.first, init_values.second} ;
	auto value = dist(m_Engine) ;
	std::cout << "[Horizontal] " << value << std::endl; 
	return value ;
}

double Accelerometer::GetVerticalAxis() {
	auto init_values = Initialize() ;
	std::uniform_int_distribution<> dist{init_values.first, init_values.second} ;
	auto value = dist(m_Engine) ;
	std::cout << "[Vertical] " << value << std::endl; 
	return value ;
}

std::pair<int, int> Accelerometer::Initialize() {
	return {-10, 10} ;
}
