#include "Clock.h"
#include <iostream>

/*
When we create multiple instances of a class that should behave like a Singleton, 
they all end up sharing the same state. For example, if you have a clock class that gets the current time, 
no matter how many clock objects you create, they will all show the same time because they are synchronized 
with the real-time clock of the system. This is why using the Singleton pattern can be beneficial; 
it prevents unnecessary duplication and keeps everything organized.
*/

int main() {
	//Clock clk ;
	std::cout << Clock::GetTimeString() << std::endl;
}


/*
| Feature                     | Singleton Pattern                                      | Monostate Pattern                                      |
|-----------------------------|-------------------------------------------------------|-------------------------------------------------------|
| Instance Enforcement         | Only one instance exists at a time                    | Multiple instances can exist, sharing the same state  |
| Instantiation Control       | Constructor is private to prevent direct instantiation | Attributes are static to enforce shared state          |
| Lazy Instantiation          | Supports lazy instantiation                            | Does not support lazy instantiation                    |
| Method Types                | Requires a static instance method                      | Methods may or may not be static                       |
| Subclassing                 | Can be subclassed and overridden                       | Static methods cannot be overridden                     |
| Flexibility                 | Can be modified to allow multiple instances            | More complex to convert existing classes to Monostate  |
*/