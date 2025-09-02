#include "Printer.h"

#include "LocalPrinter.h"


Printer& Printer::GetInstance(const std::string& key) {
	if (key == "local") {
		return LocalPrinter::GetInstance();
	}
}

//If you add new printers, you can add more conditions here. violate Open-Closed Principle.