#pragma once
#include "NetworkPrinter.h"
#include "Photocopier.h"

class MultiFunctionPrinter : public NetworkPrinter, public Photocopier {

public:
	void print() const;

	MultiFunctionPrinter(const char* model, double price, Print_Type type, bool Color_print, const char* scanner_type, const char* connection_type);

protected:
	void printNeededM() const;

private:
	const char* scanner_type_;
};