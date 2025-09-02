#include "LocalPrinter.h"

void PrintSales() {
	Printer::GetInstance("local").Print("Sales data");
}

int main() {
	auto& p = Printer::GetInstance("local");
	p.Print("Printing data to local printer");
	PrintSales();
}

/*
Issues with Singleton Pattern:
Direct usage of the Singleton class name violates the dependency inversion principle.
Makes unit testing difficult as it cannot be replaced with a mock object.

Example Implementation:
A LocalPrinter class is created to manage a printer, ensuring only one instance exists.
The class contains a print method that outputs a message to the console.

Proposed Solutions:
Instead of using the LocalPrinter directly, inherit from a base class called Printer.
This allows for different types of printers and supports easier unit testing by enabling mock object usage.
*/