// TempTemp.h
#pragma once
#include <vector>
#include "Device.h"

#include "List.h"
#include "Print_Type.h"
#include <string>


template <typename T>
class List {
public:
    struct Node {
        T* device;
        Node* next;
        Node* prev;
        Node(T* device, Node* prev = nullptr, Node* next = nullptr) : device(device), prev(prev), next(next) {}
    };
    Node* head;
    Node* tail;
    List() : head(nullptr), tail(nullptr) {}
    ~List() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void addDevice(T* device) {
        Node* node = new Node(device, tail);
        if (tail != nullptr) {
            tail->next = node;
        }
        tail = node;
        if (head == nullptr) {
            head = node;
        }
    }
    void removeDevice(const char* model) {
        Node* node = head;
        while (node != nullptr) {
            if (node->data.getModel() == model) {
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
    void displayDevices() const {
        Node* node = head;
        while (node != nullptr) {
            std::cout << node->device << std::endl;
            node = node->next;
        }
    }
    void SortModel() {
        if (head == nullptr) {
            return;
        }
        Node* end = nullptr;
        bool swapped;
        do {
            swapped = false;
            Node* current = head;
            while (current->next != end) {
                if (current->data < current->next->device) {
                    T temp = current->data;
                    current->data = current->next->device;
                    current->next->device = temp;
                    swapped = true;
                }
                current = current->next;
            }
            end = current;
        } while (swapped);
    }
    T* searchDevice(const char* model) const {
        Node* node = head;
        while (node != nullptr) {
            if (node->data == model) {
                return &node->data;
            }
            node = node->next;
        }
        return nullptr;
    }
    std::vector<T> getDevices() const {
        std::vector<T> devices;
        Node* node = head;
        while (node != nullptr) {
            devices.push_back(node->data);
            node = node->next;
        }
        return devices;
    }
};

