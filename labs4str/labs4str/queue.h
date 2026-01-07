#pragma once
template<typename T>
struct Node {
    T data;
    Node* next;
    Node(const T& val) : data(val), next(nullptr) {}
};

template<typename T>
class TQueue {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    TQueue();
    ~TQueue();

    void enque(const T& elem);
    void enque_middle(const T& elem);
    void deque();
    T peak();
    bool isEmpty();
    void clear();
};

template<typename T>
TQueue<T>::TQueue() : head(nullptr), tail(nullptr), size(0) {}


template<typename T>
TQueue<T>::~TQueue() {
    clear();
}

template<typename T>
void TQueue<T>::enque(const T& elem) {
    Node<T>* newNode = new Node<T>(elem);
    if (!tail) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template<typename T>
void TQueue<T>::enque_middle(const T& elem) {
    if (size <= 1) {
        enque(elem);
        return;
    }

    Node<T>* newNode = new Node<T>(elem);
    Node<T>* current = head;

    int Pos = (size % 2 == 0) ? size / 2 : size / 2 + 1;

    for (int i = 1; i < Pos; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    if (current == tail) {
        tail = newNode;
    }

    size++;
}

template<typename T>
void TQueue<T>::deque() {
    if (!head) return;
    Node<T>* tmp = head;
    head = head->next;
    if (!head)
        tail = nullptr;
    delete tmp;
    tmp = nullptr;
    size--;
}

template<typename T>
T TQueue<T>::peak() {
    if (!head) {
        throw std::runtime_error("очередь пустая");
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
