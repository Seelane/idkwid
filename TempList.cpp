//#pragma once
//#include "TempList.h"
//
//template <typename T>
//List<T>::Node::Node(const T& device, Node* prev, Node* next) : device(device), prev(prev), next(next) {}
//
//template <typename T>
//List<T>::List() : head(nullptr), tail(nullptr) {}
//
//template <typename T>
//List<T>::~List() {
//    while (head != nullptr) {
//        Node* temp = head;
//        head = head->next;
//        delete temp;
//    }
//}
//
//template <typename T>
//void List<T>::addDevice(const T& device) {
//    Node* node = new Node(device, tail);
//    if (tail != nullptr) {
//        tail->next = node;
//    }
//    tail = node;
//    if (head == nullptr) {
//        head = node;
//    }
//}
//
//template <typename T>
//void List<T>::removeDevice(const char* model) {
//    Node* node = head;
//    while (node != nullptr) {
//        if (node->device.getModel() == model) {
//            if (node->prev != nullptr) {
//                node->prev->next = node->next;
//            }
//            if (node->next != nullptr) {
//                node->next->prev = node->prev;
//            }
//            if (node == head) {
//                head = node->next;
//            }
//            if (node == tail) {
//                tail = node->prev;
//            }
//            delete node;
//            return;
//        }
//        node = node->next;
//    }
//}
//
//
//template <typename T>
//void List<T>::displayDevices() const {
//    Node* node = head;
//    while (node != nullptr) {
//        //        node->device.printInfo();
//        std::cout << node->device << std::endl;
//        node = node->next;
//    }
//}
//
////template <typename T>
////void List<T>::SortColorPrint() {
////    if (head == nullptr) {
////        return;
////    }
////
////    Node* end = nullptr;
////
////    bool swapped;
////    do {
////        swapped = false;
////        Node* current = head;
////
////        while (current->next != end) {
////            if (current->device.getColorPrint() > current->next->device.getColorPrint()) {
////                Device temp = current->device;
////                current->device = current->next->device;
////                current->next->device = temp;
////
////                swapped = true;
////            }
////            current = current->next;
////        }
////        end = current;
////    } while (swapped);
////}
//
//template <typename T>
//void List<T>::SortModel() {
//    if (head == nullptr) {
//        return;
//    }
//
//    Node* end = nullptr;
//
//    bool swapped;
//    do {
//        swapped = false;
//        Node* current = head;
//
//        while (current->next != end) {
//            if (current->device < current->next->device) {
//                Device temp = current->device;
//                current->device = current->next->device;
//                current->next->device = temp;
//
//                swapped = true;
//            }
//            current = current->next;
//        }
//        end = current;
//    } while (swapped);
//}
//
//template <typename T>
//T* List<T>::searchDevice(const char* model) const {
//
//    Node* node = head;
//    while (node != nullptr) {
//        if (node->device == model) {
//            return &node->device;
//        }
//        node = node->next;
//    }
//    return nullptr;
//}
//
//
//template <typename T>
//std::vector<T> List<T>::getDevices() const {
//    std::vector<T> devices;
//    Node* node = head;
//    while (node != nullptr) {
//        devices.push_back(node->device);
//        node = node->next;
//    }
//    return devices;
//}
