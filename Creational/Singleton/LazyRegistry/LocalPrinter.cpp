#include "LocalPrinter.h"
#include <iostream>
#include "PrinterProvider.h"

void LocalPrinter::Print(const std::string& data)
{
	std::cout << "[LOCALPRINTER]" << data << '\n' ;
}

PrinterPtr LocalPrinter::GetInstance() 
{
	/*static LocalPrinter instance ;
	return instance ;*/  //It won't provide delete control
	std::cout << "LocalPrinter instance created\n";
	return std::shared_ptr<LocalPrinter>{new LocalPrinter{}};
}
