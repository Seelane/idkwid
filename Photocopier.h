#pragma once
#include "PrintingDevice.h"

class Photocopier : public PrintingDevice {

public:
	void print() const;

	void setScannerType(const char* scanner_type);
	const char* getScannerType() const;

	Photocopier(const char* model, double price, Print_Type type, bool Color_print, const char* scanner_type);


protected:
	void printNeededPc() const;
	void printNeededPr() const;

private:
	const char* scanner_type_;
};