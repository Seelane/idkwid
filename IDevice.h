#pragma once
#include "Print_Type.h"

class IDevice {
public:
	virtual void setModel(const char* model)  = 0;
	virtual void setPrice(double price)  = 0;
	virtual void setType(Print_Type type)  = 0;
	virtual const char* getModel() const = 0;
	virtual Print_Type getType() const = 0;
	virtual double getPrice() const = 0;

protected:
	virtual ~IDevice() = default;
};
