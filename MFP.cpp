#include "MFP.h"

MultiFunctionPrinter::MultiFunctionPrinter(const char* model, double price, Print_Type type, bool Color_print, const char* scanner_type) : PrintingDevice(model, price, type, Color_print)
{
	setScannerType(scanner_type);
}

void MultiFunctionPrinter::print() const
{
	std::cout << "MultiFunctionPrinter:\n";
	printNeededP();
	std::cout << "\nScanner Type: " << scanner_type_;
	std::cout << "\n#=======================#\n\n";
}

void MultiFunctionPrinter::setScannerType(const char* scanner_type)
{
	scanner_type_ = scanner_type;
}

const char* MultiFunctionPrinter::getScannerType() const
{
	return scanner_type_;
}

void MultiFunctionPrinter::printNeededMF()
{
	printNeededP();
	std::cout << "\nScanner Type: " << scanner_type_;
}
