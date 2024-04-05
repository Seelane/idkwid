#pragma once
#include "Device.h"

class PrintingDevice : public Device {
public:
	PrintingDevice(const char* model, Print_Type type, bool Color_print, double price) : Device(model, type, Color_print, price) {}
};
