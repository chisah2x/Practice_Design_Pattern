#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
class Clock
{
//Using the C++17 inline keyword allows defining static members within the class, 
// avoiding external definitions.

//The Monostate pattern enforces singular behavior through behavior rather than structure, 
// contrasting with the Singleton pattern.
	inline static int m_Hour;
	inline static int m_Minute;
	inline static int m_Second;
	static void CurrentTime();
	Clock();
public:
	static int GetHour();
	static int GetMinute();
	static int GetSecond();
	static std::string GetTimeString();
};

//Design Considerations
//Allowing multiple instances can create confusion, as it may imply different states for each instance.
//To enforce singularity, the constructor is made private, and methods are accessed statically through the class name.With static attributes, all instances refer to the same single copy, reducing memory usage.

