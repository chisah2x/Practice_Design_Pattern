#include "LocalPrinter.h"
#include "PrinterProvider.h"

void PrintSales() {
	//Printer::GetInstance("local").Print("Sales data");
	auto p = PrinterProvider::GetPrinterPtr("local") ;
	if(p)
		p->Print("Sales data") ;
}

int main() {
	auto p = PrinterProvider::GetPrinterPtr("pdf");
	if(p)
		p->Print("Printing data to the printer") ;
	PrintSales() ; 
}
