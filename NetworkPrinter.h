#pragma once
#include "PrintingDevice.h"

class NetworkPrinter : public PrintingDevice {

public:
	NetworkPrinter(const char* model, double price, Print_Type type, bool Color_print, const char* connection_type);

	void print() const;

	void setConnectionType(const char* connection_type);
	const char* getConnectionType() const;

protected:
	void printNeeded() const;

private:
	const char* connection_type_;

};