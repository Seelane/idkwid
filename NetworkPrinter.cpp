#include "NetworkPrinter.h"

NetworkPrinter::NetworkPrinter(const char* model, double price, Print_Type type, bool Color_print, const char* connection_type) : PrintingDevice(model, price, type, Color_print)
{
	setConnectionType(connection_type);
}

void NetworkPrinter::print() const {
	std::cout << "Network Printer:\n";
	printNeededP();
	std::cout << "\nConnection Type: " << connection_type_;
	std::cout << "\n#=======================#\n\n";
}

void NetworkPrinter::printNeededN() const 
{
	printNeededP();
	std::cout << "\nConnection Type: " << getConnectionType();
}

void NetworkPrinter::setConnectionType(const char* connection_type)
{
	connection_type_ = connection_type;
}

const char* NetworkPrinter::getConnectionType() const
{
	return connection_type_;
}


