#pragma once
#include <string_view>
#include <string>
struct Position;
class Vehicle ;
Vehicle * Create(
	std::string_view type, 
	int mSpeed, 
	int mHitPoints,
	const std::string& mName,
	std::string_view animFile,
	const Position& mPosition);

