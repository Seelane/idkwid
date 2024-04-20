// TempTemp.h
#pragma once
#include <vector>
#include "PrintingDevice.h"
#include "List.h"
#include "Print_Type.h"
#include <string>
#include "MFP.h"
#include "NetworkPrinter.h"
template <typename T>
class List {
public:
    struct Node {
        T* data;
        Node* next;
        Node* prev;
        Node(T* data, Node* prev = nullptr, Node* next = nullptr) : data(data), prev(prev), next(next) {}
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
    void addDevice(T* data) {
        Node* node = new Node(data, tail);
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
    void print() const {
        Node* node = head;
        while (node != nullptr) {
            std::cout << node->data << std::endl;
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
                if (current->data < current->next->data) {
                    T temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
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

