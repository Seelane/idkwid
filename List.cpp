// List.cpp
#pragma once
#include "List.h"

DeviceList::Node::Node(const Device& device, Node* prev = nullptr, Node* next = nullptr) : device(device), prev(prev), next(next) {}

DeviceList::DeviceList() : head(nullptr), tail(nullptr) {}

DeviceList::~DeviceList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void DeviceList::addDevice(const Device& device) {
    Node* node = new Node(device, tail);
    if (tail != nullptr) {
        tail->next = node;
    }
    tail = node;
    if (head == nullptr) {
        head = node;
    }
}

void DeviceList::removeDevice(const char* model) {
    Node* node = head;
    while (node != nullptr) {
        if (node->device.getModel() == model) {
            if (node->prev != nullptr) {
                node->prev->next = node->next;
            }
            if (node->next != nullptr) {
                node->next->prev = node->prev;
            }
            if (node == head) {
                head = node->next;
            }
            if (node == tail) {
                tail = node->prev;
            }
            delete node;
            return;
        }
        node = node->next;
    }
}


void DeviceList::displayDevices() const {
    Node* node = head;
    while (node != nullptr) {
//        node->device.printInfo();
        std::cout << node->device << std::endl;
        node = node->next;
    }
}

void DeviceList::SortColorPrint() {
    if (head == nullptr) {
        return;
    }

    Node* end = nullptr;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;

        while (current->next != end) {
            if (current->device.getColorPrint() > current->next->device.getColorPrint()) {
                Device temp = current->device;
                current->device = current->next->device;
                current->next->device = temp;

                swapped = true;
            }
            current = current->next;
        }
        end = current;
    } while (swapped);
}

void DeviceList::SortModel() {
    if (head == nullptr) {
        return;
    }

    Node* end = nullptr;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;

        while (current->next != end) {
            if (current->device < current->next->device) {
                Device temp = current->device;
                current->device = current->next->device;
                current->next->device = temp;

                swapped = true;
            }
            current = current->next;
        }
        end = current;
    } while (swapped);
}

void DeviceList::SortPrice() {
    if (head == nullptr) {
        return;
    }

    Node* end = nullptr;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;

        while (current->next != end) {
            if (current->device.getPrice() > current->next->device.getPrice()) {
                Device temp = current->device;
                current->device = current->next->device;
                current->next->device = temp;

                swapped = true;
            }
            current = current->next;
        }
        end = current;
    } while (swapped);
}

Device* DeviceList::searchDevice(const char* model) const {

    Node* node = head;
    while (node != nullptr) {
        if (node->device == model) {
            return &node->device;
        }
        node = node->next;
    }
    return nullptr; 
}


std::vector<Device> DeviceList::getDevices() const {
    std::vector<Device> devices;
    Node* node = head;
    while (node != nullptr) {
        devices.push_back(node->device);
        node = node->next;
    }
    return devices;
}


int DeviceList::getSize() const {
    Node* node = head;
    int counterDevice = 0;

    while (node != nullptr) {
        counterDevice++;
    }
    return counterDevice;
}