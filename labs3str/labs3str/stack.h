#pragma once
#include <iostream>

template<typename T>
struct StackNode {
    T data;
    StackNode* next;
    StackNode(const T& val) : data(val), next(nullptr) {}
};

template<typename T>
class TStack {
private:
    StackNode<T>* head;

public:
    TStack();
    ~TStack();
    void push(const T& elem);
    void pop();
    T peek();
    bool isEmpty();
    void clear();
};
template<typename T>
TStack<T>::TStack():head(nullptr){}

template<typename T>
TStack<T>::~TStack() {
    clear();
}
template<typename T>
void TStack<T>::push(const T& elem) {
    StackNode<T>* newNode = new StackNode<T>(elem);
    newNode->next = head;
    head = newNode;
}

template<typename T>
void TStack<T>::pop() {
    if (!head) return;
    StackNode<T>* temp = head;
    head = head->next;
    delete temp;
}

template<typename T>
T TStack<T>::peek() {
    if (!head) {
        throw std::runtime_error("стек пустой");
    }
    return head->data;
}

template<typename T>
bool TStack<T>::isEmpty() {
    return head == nullptr;
}

template<typename T>
void TStack<T>::clear() {
    while (!isEmpty()) {
        StackNode<T>* temp = head;
        head = head->next;
        delete temp;
    }
}