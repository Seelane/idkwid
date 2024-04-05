#include "Statistic.h"
using namespace std;

void Statistics::print() const {
	for (const auto& element : printers) {
		cout << element.first->getModel() << "\t\t" << element.first->getPrice() * element.second << "\t\t" << element.second << endl;
	}
	cout << "Total price: " << total_price << endl;
}

void Statistics::sum(Device* device){
	if (printers.count(device)) {
		printers[device]++;
	}
	else {
		printers.insert({ device, 1 });
	}
	total_price += device->getPrice();
}

void Statistics::sum(DeviceList* devic) {
	for (int i = 0; i < devic->getSize(); i++) sum(&devic[i]);
}


