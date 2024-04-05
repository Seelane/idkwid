#pragma once
#include <map>
#include "TempTemp.h"
using namespace std;

class Statistics {
public:
	Statistics() {
		printers = {};
		total_price = 0;
	}

	void print() const;
	void sum(Device* device);
	void sum(DeviceList* devic);
// void sum(DeviceList* device);
//

private:
	std::map<Device*, double> printers;
	double total_price;
};