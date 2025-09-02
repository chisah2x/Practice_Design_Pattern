#pragma once
#include "Printer.h"
class PDFPrinter :public Printer
{
	PDFPrinter() = default;

public:
	void Print(const std::string& data) override;
	static PrinterPtr GetInstance();
};

