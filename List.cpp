// List.cpp
#include "List.h"

DeviceList::Node::Node(Device device, Node* prev = nullptr, Node* next = nullptr) : device(std::move(device)), next(next), prev(prev) {}

DeviceList::DeviceList() : head(nullptr), tail(nullptr) {}

DeviceList::~DeviceList() {
    while (head != nullptr) {
        const Node* temp = head;
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
    const Node* node = head;
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
    const Node* node = head;
    while (node != nullptr) {
        node->device.printInfo();
        std::cout << node->device << std::endl;
        node = node->next;
    }
}

void DeviceList::SortPrice() const
{
    if (head == nullptr) {
        return;
    }

    const Node* end = nullptr;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;

        while (current->next != end) {
            if (current->device.getPrice() > current->next->device.getPrice()) {
                const Device temp = current->device;
                current->device = current->next->device;
                current->next->device = temp;

                swapped = true;
            }
            current = current->next;
        }
        end = current;
    } while (swapped);
}

void DeviceList::SortModel() const
{
    if (head == nullptr) {
        return;
    }

    const Node* end = nullptr;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;

        while (current->next != end) {
            if (current->device < current->next->device) {
                const Device temp = current->device;
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
    const Node* node = head;
    while (node != nullptr) {
        devices.push_back(node->device);
        node = node->next;
    }
    return devices;
}


int DeviceList::getSize() const {
    const Node* node = head;
    int counterDevice = 0;

    while (node != nullptr) {
        counterDevice++;
    }
    return counterDevice;
}