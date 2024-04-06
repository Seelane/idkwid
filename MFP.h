#pragma once
#include "PrintingDevice.h"

class MultiFunctionPrinter : public PrintingDevice {

public:
	void print() const override;

	void setScannerType(const char* scanner_type);
	const char* getScannerType() const;

	MultiFunctionPrinter(const char* model, double price, Print_Type type, bool Color_print, const char* scanner_type);


protected:
	void printNeededMF();

private:
	const char* scanner_type_;
};
