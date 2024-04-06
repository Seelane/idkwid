// Device.h
#pragma once
#include <string>
#include <iostream>
#include "IDevice.h"

class Device : public IDevice {
public:
	Device(const char* model, double price);

	static int totalPrinters;
	void setModel(const char* model) override;
	void setPrice(double price) override;

	const char* getModel() const override;
	double getPrice() const override;
	//спорный момент
	void printInfo()const;


	friend std::ostream& operator << (std::ostream& xd, const Device& device);
	bool operator < (const Device& device) const
	{
		return printerNumber_ < device.printerNumber_;
	}
	bool operator == (const char* device) const
	{
		return model_ == device;
	}

protected:
	void printNeeded() const;

private:
	char* model_;
//	bool Color_print_;
//	Print_Type type_;
	int printerNumber_;
	double price_;
};
