// List.h
#pragma once
#include <vector>
#include "Device.h"
#include "Print_Type.h"
#include <string>



class DeviceList {
public:
    struct Node {
        Device device;
        Node* next;
        Node* prev;

        Node(Device device, Node* prev, Node* next);
    };

    Node* head;
    Node* tail;

    DeviceList();

    ~DeviceList();

    void addDevice(const Device& device);

    void removeDevice(const char* model);

    void displayDevices() const;

    void SortColorPrint() const; // сортировка по признаку Color Print
    void SortModel() const;
    void SortPrice() const;

    Device* searchDevice(const char* model) const;

    int getSize() const;

    std::vector<Device> getDevices() const;
};