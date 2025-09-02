#include "PrinterProvider.h"
#include <iostream>

void PrinterProvider::RegisterCreator(const std::string& key, Creator creator) {
	std::lock_guard lock{ m_mtx };
	if (auto it = m_Printers.find(key); it == end(m_Printers)) {
		m_Printers[key].m_Creator = creator;
	}
	else {
		std::cout << "Already registered\n";
	}
}

PrinterPtr PrinterProvider::GetPrinter(const std::string& key) {
	std::lock_guard lock{ m_mtx };
	if (auto it = m_Printers.find(key); it != end(m_Printers)) {
		if (!m_Printers[key].m_Printer)
		{
			m_Printers[key].m_Printer = m_Printers[key].m_Creator();
		}
		return m_Printers[key].m_Printer;
	}
	std::cout << "Unknown key\n";
	return nullptr;
}

/*
Sure! Let's break down the key concepts from the video in a clear and structured way using bullet points and bold text for better readability.

### Lazy Instantiation for Singletons

- **What is Lazy Instantiation?**
  - Lazy instantiation means creating an object only when it is needed, rather than at the start of the program. This can save resources and improve performance.

- **Why Use Lazy Instantiation?**
  - It avoids unnecessary memory usage by not creating instances until they are required.
  - It allows for better control over the lifecycle of the objects.

### Code Refactoring Steps

- **Initial Setup:**
  - The code starts with a **Printer Provider** that automatically registers printer instances when they are created.
  - This is known as **eager instantiation**, where instances are created upfront.

- **Switching to Lazy Instantiation:**
  - The goal is to modify the **get printer** function to check if a printer instance exists in a map.
  - If it does not exist, it will create a new instance, add it to the map, and return it.

- **Callback Function:**
  - To avoid tight coupling between the printer provider and printer classes, a **callback function** is introduced.
  - This function will be responsible for creating instances of printer classes when needed.

### Memory Management

- **Using Smart Pointers:**
  - Instead of using raw pointers, **shared pointers** are used to manage memory automatically.
  - This helps in avoiding memory leaks since shared pointers will automatically delete the instance when it is no longer needed.

### Code Structure Changes

- **Instance Information Struct:**
  - A struct is created to hold information about the printer instance, including:
	- A pointer to the printer (using smart pointer).
	- The callback function for creating the instance.

- **Registering Creators:**
  - The method to register printers is changed to **register creator**, which specifies the key and the creator function.

### Implementation of Get Printer

- **Single Function for Getting Printers:**
  - The code now has a single function called **get printer** that returns a shared pointer of the printer.

- **Searching for Keys:**
  - When a key is searched in the map:
	- If found, it checks if the corresponding printer instance exists.
	- If not, it invokes the creator to create the instance and adds it to the map.

### Example of Lazy Instantiation
  - This would create the instance only when the method is called, but it limits control over when the instance is destroyed.

The **callback function** plays a crucial role in the lazy instantiation of printer instances. Here’s how it helps:

### Key Functions of the Callback

- **Decoupling Components:**
  - The callback function allows the **Printer Provider** to remain independent of the specific printer classes. This means the provider does not need to know the details of how to create each printer instance.
- **Flexibility:**
  - Different printer types can have their own specific creation logic encapsulated within their respective callback functions. This allows for flexibility in how instances are created without modifying the printer provider's code.

- **Simplified Registration:**
  - The printer classes can register their creation logic (the callback) with the printer provider. This registration process is straightforward and allows the provider to manage multiple printer types easily.

*/