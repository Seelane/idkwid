// Device.h
#pragma once
#include "Print_Type.h"
#include <string>
#include <iostream>
#include "IDevice.h"

class Device : public IDevice {
public:
	static int totalPrinters;
	void setModel(const char* model);
	void setPrice(double price);
	void setType(Print_Type type);

	Device(const char* model,Print_Type type, bool Color_print, double price);

	const char* getModel() const override;
	Print_Type getType() const override;
	bool getColorPrint() const;
	double getPrice() const override;
	void printInfo()const;
	void printNeeded() const;

	friend std::ostream& operator << (std::ostream& xd, const Device& device);
	bool operator < (const Device& device) 
	{ return printerNumber_ < device.printerNumber_; }
	bool operator == (const char* device)
	{
		return model_ == device;
	}

private:
	char* model_;
	int year_;
	bool Color_print_;
	Print_Type type_;
	int printerNumber_;
	double price_;
	std::string getPrintType() const;
};

