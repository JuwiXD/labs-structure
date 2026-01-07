#pragma once
#include <iostream>

template<typename T>
struct QueueNode {
    T data;
    QueueNode* next;
    QueueNode(const T& val) : data(val), next(nullptr) {}
};

template<typename T>
class TQueue {
private:
    QueueNode<T>* head;
    QueueNode<T>* tail;

public:
    TQueue();
    ~TQueue();
    void enque(const T& elem);

    void deque();

    T peak();

    bool isEmpty();

    void clear();
};
template<typename T>
TQueue<T>::TQueue() : head(nullptr), tail(nullptr) {}

template<typename T>
TQueue<T>::~TQueue() {
    clear();
}
template<typename T>
void TQueue<T>::enque(const T& elem) {
    QueueNode<T>* newNode = new QueueNode<T>(elem);
    if (!tail) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}
template<typename T>
void TQueue<T>::deque() {
    if (!head) return;
    QueueNode<T>* temp = head;
    head = head->next;
    if (!head)
        tail = nullptr;
    delete temp;
}
template<typename T>
T TQueue<T>::peak() {
    if (!head) {
        throw std::runtime_error("стек пустой");
    }
    return head->data;
}
template<typename T>
bool TQueue<T>::isEmpty() {
    return head == nullptr;
}
template<typename T>
void TQueue<T>::clear() {
    while (!isEmpty()) {
        deque();
    }
}