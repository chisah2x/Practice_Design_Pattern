#include "LocalPrinter.h"
#include "PDFPrinter.h"
#include "PrinterProvider.h"

void PrintSales() {
	//Printer::GetInstance("local").Print("Sales data");
	auto p = PrinterProvider::GetPrinter("local") ;
	if(p)
		p->Print("Sales data") ;
}

int main() {
	PrinterProvider::RegisterCreator("local", &LocalPrinter::GetInstance);
	PrinterProvider::RegisterCreator("pdf", &PDFPrinter::GetInstance);
	PrintSales() ; 

	auto p = PrinterProvider::GetPrinter("pdf");
	if (p)
		p->Print("Printing data to printer");
}
