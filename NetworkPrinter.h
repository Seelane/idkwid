#pragma once
#include "PrintingDevice.h"

class NetworkPrinter : public PrintingDevice {
private:
	const char* connection_type_;
public:
	NetworkPrinter(const char* model, Print_Type type, bool Color_print, double price, const char* connection_type) : PrintingDevice(model, type, Color_print, price), connection_type_(connection_type) {}
	void printInfo() const override {
		std::cout << "Network Printer:\n";
		Device::printInfo();
		std::cout << "Connection Type: " << connection_type_ << "\n";
	}
};