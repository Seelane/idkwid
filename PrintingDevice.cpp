#include "PrintingDevice.h"



PrintingDevice::PrintingDevice(const char* model, double price, Print_Type type, bool Color_print) : Device(model, price)
{
	setColor_print(Color_print);
	setType(type);
}

void PrintingDevice::print() const {
	std::cout << "Printing Device:\n";
	printNeeded();
	std::cout << "Print type: " << getType();
	std::cout << "\nColor print: " << (getColor_print() ? "Yes" : "No");
	std::cout << "\n#=======================#\n\n";
}

void PrintingDevice::printNeededP() const
{
	printNeeded();
	std::cout << "Print type: " << getType();
	std::cout << "\nColor print: " << getColor_print();
}



std::string PrintingDevice::setType(Print_Type type)
{
	switch (type) {
	case Print_Type::LASER: printtype = "Laser";
	case Print_Type::FLOW: printtype = "Flow";
	case Print_Type::MATRIC: printtype = "Matric";
	}
	return std::string("Unknown");
}

void PrintingDevice::setColor_print(bool Color_print)
{
	Colorprint = Color_print ? true : false;
}

std::string PrintingDevice::getType() const
{
	return printtype;
}

bool PrintingDevice::getColor_print() const
{
	return Colorprint;
}




