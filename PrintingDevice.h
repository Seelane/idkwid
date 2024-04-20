#pragma once
#include "Print_Type.h"
#include "Device.h"
#include <string>

class PrintingDevice : public Device {
public:
	PrintingDevice(const char* model, double price, Print_Type type, bool Color_print);

	virtual void print() const;

	std::string setType(Print_Type type);
	void setColor_print(bool Color_print);

	std::string getType() const;
	bool getColor_print() const;

protected:
	void printNeeded() const;

private:
	std::string printtype;
	bool Colorprint;

};