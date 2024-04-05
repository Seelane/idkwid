#pragma once
#include <iostream>
#include "Device.h"
//#include "List.h"
//#include "TempTemp.h"
//#include "Statistic.h"
#include "NetworkPrinter.h"
#include "MFP.h"
using namespace std;

void text_separator() {
    cout << "#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n";
    cout << "#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n\n";
}

int main() {
    //lab1
    int year = 2022;
    Device LaserPrinter("Pantum P2207", Print_Type::LASER, false, 25000);
    Device FlowPrinter("HP Ink Tank 315", Print_Type::FLOW, true, 27250);
    Device MatrixPrinter("OKI Ml 390FB", Print_Type::MATRIC, false, 22750);
    Device MatrixPrinter2 = MatrixPrinter;

    LaserPrinter.printInfo();
    FlowPrinter.printInfo();
    MatrixPrinter.printInfo();
    cout << "Wait 1#" << endl << endl;
    //lab2
 /*   DeviceList list;
    list.addDevice(LaserPrinter);
    list.addDevice(FlowPrinter);
    list.addDevice(MatrixPrinter);

    list.displayDevices();
    cout << "Wait 2#" << endl << endl;

    list.SortPrice();
    list.displayDevices();

    cout << "Wait 3#" << endl << endl;*/
    text_separator();

    //lab5
 /*   Statistics st;
    st.sum(&LaserPrinter);
    st.sum(&FlowPrinter);
    st.sum(&LaserPrinter); st.sum(&LaserPrinter);
    st.sum(&MatrixPrinter); st.sum(&MatrixPrinter); st.sum(&MatrixPrinter); st.sum(&MatrixPrinter);
    st.print();*/
    
    
    cout << "Wait 4#\n\n";

    //lab6
    NetworkPrinter networkPrinter("HP LaserJet Pro M501dn", Print_Type::LASER, false, 60000, "Wi-Fi");
    MultiFunctionPrinter mfp("Canon MegaTank MAXIFY GX4020", Print_Type::FLOW, true, 45000, "Contact Image Sensor");
    IDevice* devices[] = { &networkPrinter, &mfp };
    for (const auto& device : devices) {
        device->printInfo();
    }
   // list.getDevices();
   // list.SortModel();
   // list.displayDevices();
   // cout << "Wait 3#" << endl << endl;
   // list.searchDevice("Pantum P2207");
   // list.displayDevices();
   // list.removeDevice("Pantum P2207");
   // list.displayDevices();
   // cout << endl << endl;
   // //lab4
   //List<Device> list1;
   // list1.addDevice(LaserPrinter);
   // list1.addDevice(FlowPrinter);
   // list1.addDevice(MatrixPrinter);

   // list1.displayDevices();
   // cout << "Wait 2#" << endl << endl;
   // list1.getDevices();
   // list1.SortModel();
   // list1.displayDevices();
   // cout << "Wait 3#" << endl << endl;
   // list1.searchDevice("Pantum P2207");
   // list1.displayDevices();
   // list1.removeDevice("Pantum P2207");
   // list1.displayDevices();
   // cout << endl << endl;

    cout << "\nSuccess?!\n";

    return 0;
}