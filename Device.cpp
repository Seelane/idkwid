// Device.cpp
#include <iostream>
#include "Device.h"
#include "List.h"
#include "TempList.h"
using namespace std;

int Device::totalPrinters = 0;

Device::Device(const char* model, double price) {
	Device::setModel(model);

//	type_ = type;
//	Color_print_ = Color_print;
	price_ = price;
	totalPrinters++;
	printerNumber_ = totalPrinters;
}

void Device::setModel(const char* model)
{
	model_ = const_cast<char*>(model);
}

//void Device::setType(Print_Type type)
//{
//	type_ = type;
//}

void Device::setPrice(double price)
{
	if (price < 0) throw std::invalid_argument("Negative price!");
	price_ = price;
}

const char* Device::getModel() const {
	return model_;
}

//Print_Type Device::getType() const {
//	return type_;
//}

//bool Device::getColorPrint() const {
//	return Color_print_;
//}

double Device::getPrice() const {
	return price_;
}

std::ostream& operator << (std::ostream& xd, const Device& device)
{
	xd << "printer #" << device.printerNumber_ << endl;
	xd << "Model: " << device.getModel() << std::endl;
	xd << "Current Price: " << device.getPrice() << std::endl;
	return xd;
}

void Device::print() const {
	cout << "Printer #" << printerNumber_ << endl;
	cout << "Model: " << model_ << endl;
//	cout << "Print Type: " << getPrintType() << endl;
//	cout << "Color Print: " << (Color_print_ ? "Yes" : "No") << endl;
	cout << "Current Price: " << getPrice();
	cout << "\n#=======================#\n\n";
}

void Device::printNeeded() const {
	cout << "Printer #" << printerNumber_ << endl;
	cout << "Model: " << model_ << endl;
	cout << "Current Price: " << getPrice() << std::endl;
}

