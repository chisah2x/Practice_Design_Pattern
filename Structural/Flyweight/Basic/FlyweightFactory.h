#pragma once
#include <unordered_map>

#include "Flyweight.h"

class FlyweightFactory
{
	inline static std::unordered_map<int, Flyweight*> m_Flyweights{};
public:
	Flyweight* GetFlyweight(int key);
	Flyweight* GetUnsharedFlyweight(int value);
};

