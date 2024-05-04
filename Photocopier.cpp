#include "Photocopier.h"

Photocopier::Photocopier(const char* model, double price, Print_Type type, bool Color_print, const char* scanner_type) 
	: PrintingDevice(model, price, type, Color_print) {
	setScannerType(scanner_type);
}

void Photocopier::print() const
{

	std::cout << "Photocopier:\n";
	printNeededPc();
	std::cout << "\nScanner Type: " << scanner_type_;
	std::cout << "\n#=======================#\n\n";
}

void Photocopier::printNeededPc() const
{
	printNeededPD();
	std::cout << "\nScanner Type: " << scanner_type_;
}

void Photocopier::printNeededPr() const
{
	std::cout << "\nScanner Type: " << scanner_type_;
}

void Photocopier::setScannerType(std::string scanner_type)
{
	scanner_type_ = scanner_type;
}

std::string Photocopier::getScannerType() const
{
	return scanner_type_;
}
