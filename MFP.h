#pragma once
#include "PrintingDevice.h"

class MultiFunctionPrinter : public PrintingDevice {
private:
	const char* scanner_type_;
public:
	MultiFunctionPrinter(const char* model, Print_Type type, bool Color_print, double price, const char* scanner_type) : PrintingDevice(model, type, Color_print, price), scanner_type_(scanner_type) {}
	void print() const {
		std::cout << "MultiFunctionPrinter:\n";
		printInfo();
		std::cout << "Scanner Type: " << scanner_type_ << "\n";
	}
};