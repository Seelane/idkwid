// Device.cpp
#include <iostream>
#include "Device.h"
//#include "List.h"
//#include "TempList.h"
using namespace std;

int Device::totalPrinters = 0;

Device::Device(const char* model, Print_Type type, bool Color_print, double price) {
	setModel(model);

	type_ = type;
	Color_print_ = Color_print;
	price_ = price;
	totalPrinters++;
	printerNumber_ = totalPrinters;
}

void Device::setModel(const char* model)
{
	model_ = const_cast<char*>(model);
}

void Device::setType(Print_Type type) 
{
	type_ = type;
}

void Device::setPrice(double price) 
{
	price_ = price;
}

const char* Device::getModel() const {
	return model_;
}

Print_Type Device::getType() const {
	return type_;
}

bool Device::getColorPrint() const {
	return Color_print_;
}

double Device::getPrice() const {
	return price_;
}

std::ostream& operator << (std::ostream& xd, const Device& device)
{
	xd << "printer #" << device.printerNumber_ << endl;
	xd << "Model: " << device.getModel() << std::endl;
	xd << "Print Type: " << device.getPrintType() << std::endl;
	xd << "Color Print: " << (device.getColorPrint() ? "Yes" : "No") << std::endl;
	xd << "Current Price: " << device.getPrice() << std::endl;
	return xd;
}

void Device::printInfo()const {
	cout << "Printer #" << printerNumber_ << endl;
	cout << "Model: " << model_ << endl;
	cout << "Release Year: " << year_ << endl;
	cout << "Print Type: " << getPrintType() << endl;
	cout << "Color Print: " << (Color_print_ ? "Yes" : "No") << endl;
	cout << "Current Price: " << getPrice() << std::endl;
}

void Device::printNeeded() const {

}


std::string Device::getPrintType() const
{
	switch (type_) {
	case Print_Type::LASER: return std::string("Laser");
	case Print_Type::FLOW : return std::string("Flow");
	case Print_Type::MATRIC : return std::string("Matric");
	}
	return std::string("Unknown");
}
