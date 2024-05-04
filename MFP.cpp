#include "MFP.h"

MultiFunctionPrinter::MultiFunctionPrinter(const char* model, 
	double price, 
	Print_Type type, 
	bool Color_print,
	const char* connection_type, 
	const char* scanner_type) 
: NetworkPrinter(model, price, type, Color_print, connection_type), 
Photocopier(model, price, type, Color_print, scanner_type)
{	
	setConnectionType(connection_type);
	setScannerType(scanner_type);
}

void MultiFunctionPrinter::print() const
{
	std::cout << "MultiFunctionPrinter:\n";
	NetworkPrinter::printNeededN();
	Photocopier::printNeededPr();

	std::cout << "\n#=======================#\n\n";
}

void MultiFunctionPrinter::printNeededM() const
{
	NetworkPrinter::printNeededN();
	Photocopier::printNeededPr();
}
