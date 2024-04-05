// Device.h
#pragma once
#include <string>
#include <iostream>
#include "IDevice.h"

class Device : public IDevice {
public:
	Device(const char* model,Print_Type type, bool Color_print, double price);

	static int totalPrinters;
	void setModel(const char* model) override;
	void setPrice(double price) override;
	void setType(Print_Type type) override;


	const char* getModel() const override;
	Print_Type getType() const override;
	bool getColorPrint() const;
	double getPrice() const override;
	//спорный момент, может развернуть преподаватель. У тебя не будет видно этого метода в MFP
	void printInfo()const;
	void printNeeded() const;

	friend std::ostream& operator << (std::ostream& xd, const Device& device);
	bool operator < (const Device& device) const
	{ return printerNumber_ < device.printerNumber_; }
	bool operator == (const char* device) const
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

