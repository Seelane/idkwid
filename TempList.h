//#pragma once
//#include <vector>
//#include "Device.h"
//#include "Print_Type.h"
//#include <string>
//
//
//template <typename T>
//class List {
//public:
//    struct Node {
//        T device;
//        Node* next;
//        Node* prev;
//
//        Node(const T& device, Node* prev = nullptr, Node* next = nullptr);
//    };
//
//    Node* head;
//    Node* tail;
//
//    List();
//
//    ~List();
//
//    void addDevice(const T& device);
//
//    void removeDevice(const char* model);
//
//    void displayDevices() const;
//
//    //void SortColorPrint(); // сортировка по признаку Color Print
//    void SortModel();
//
//
//    T* searchDevice(const char* model) const;
//
//    std::vector<T> getDevices() const;
//};