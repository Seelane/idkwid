#pragma once
#include "PrintingDevice.h"

class Photocopier : public PrintingDevice {

public:
	void print() const;

	void setScannerType(std::string scanner_type);
	std::string getScannerType() const;

	Photocopier(const char* model, double price, Print_Type type, bool Color_print, const char* scanner_type);


protected:
	void printNeededPc() const;
	void printNeededPr() const;
private:
	std::string scanner_type_;
};