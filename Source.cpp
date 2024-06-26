#include <iostream>
#include "Device.h"
#include "List.h"
#include "TempTemp.h"
#include "Statistic.h"
#include "PrintingDevice.h"
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
    
    try
    {
        PrintingDevice LaserPrinter("Pantum P2207", -25000, Print_Type::LASER, false);
            LaserPrinter.print();
    }
    catch (const std::invalid_argument& error)
    {
        cout << error.what() << endl;
    }
    catch (const std::exception& error)
    {
        cout << error.what() << endl;
    }
    catch (...)
    {
        cout << "Error" << endl;
    }

    PrintingDevice LaserPrinter("Pantum P2207", 25000, Print_Type::LASER, false);
    PrintingDevice FlowPrinter("HP Ink Tank 315", 27250, Print_Type::FLOW, true);
    PrintingDevice MatrixPrinter("OKI Ml 390FB", 22750, Print_Type::MATRIC, false);
    PrintingDevice MatrixPrinter2 = MatrixPrinter;

    FlowPrinter.print();
    MatrixPrinter.print();
    cout << "Wait 1#" << endl << endl;
    //lab2
    DeviceList list;
    list.addDevice(LaserPrinter);
    list.addDevice(FlowPrinter);
    list.addDevice(MatrixPrinter);

    list.displayDevices();
    cout << "Wait 2#" << endl << endl;

    list.SortPrice();
    list.displayDevices();

    cout << "Wait 3#" << endl << endl;
    text_separator();

    //lab5
    Statistics st;
    st.sum(&LaserPrinter);
    st.sum(&FlowPrinter);
    st.sum(&LaserPrinter); st.sum(&LaserPrinter);
    st.sum(&MatrixPrinter); st.sum(&MatrixPrinter); st.sum(&MatrixPrinter); st.sum(&MatrixPrinter);
    st.print();


    cout << "Wait 4#\n\n";

    //lab6
    NetworkPrinter networkPrinter("HP LaserJet Pro M501dn", 60000, Print_Type::LASER, false, "Wi-Fi");
    MultiFunctionPrinter mfp("Canon MegaTank MAXIFY GX4020", 45000, Print_Type::FLOW, true, "Wi-Fi", "Contact Image Sensor");
    networkPrinter.print();
    mfp.print();


    List<IDevice> list1;
     list1.addDevice(&LaserPrinter);
     list1.addDevice(&FlowPrinter);
     list1.addDevice(&MatrixPrinter);
    list1.addDevice(&networkPrinter);
    list1.addDevice(&mfp);
        std::cout << "axaxaxaxaxxaxaxaxaxaxax\n\n";
        list1.print();

    cout << "\nSuccess?!\n";
    system("pause");
    return 0;
}
