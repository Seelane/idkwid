#pragma once
#include "Print_Type.h"

class IDevice {
public:
	virtual void printInfo() const = 0;
	virtual void setModel(const char* model) const = 0;
	virtual void setPrice(double price) const = 0;
	virtual void setType(Print_Type type) const = 0;
	virtual const char* getModel() const = 0;
	virtual Print_Type getType() const = 0;
	virtual double getPrice() const = 0;

protected:
	virtual ~IDevice() = default;
};
