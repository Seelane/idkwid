#pragma once
#include "Print_Type.h"

class IDevice {
public:
	virtual void setModel(const char* model) = 0;
	virtual void setPrice(double price) = 0;
	virtual const char* getModel() const = 0;
	virtual double getPrice() const = 0;
	virtual void print() const = 0;

protected:
	virtual void printNeeded() const = 0;
	virtual ~IDevice() = default;
};