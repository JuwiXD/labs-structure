#include "list.h"
void createLikestack(Node*& head, std::istream& in) {
    int data;
    while (in >> data) {
        AddToHead(head, data);
    }
}
void createLikeQueue(Node*& head, std::istream& in) {
    int data;
    if (in >> data) {
        head = new Node(data);
        Node* tail = head;
        while (in >> data) {
            tail->next = new Node(data);
            tail = tail->next;
        }
    }
}

void AddToHead(Node*& head, int data) {
    Node* p = new Node(data);
    p->next = head;
    head = p;
}

void AddAfterElem(Node* head, int data, int elem) {
    Node* p = head;
    while (p) {
        if (p->data == elem) {
            AddAfterElem(p,data);
            break;
        }
        p = p->next;
    }
}

void AddAfterElem(Node* ptr, int data) {
    if (ptr)
        ptr->next = new Node(data, ptr->next);
}

void AddBeforeElem(Node*& head, int data, int elem) {
    if (!head) 
        return;

    if (head->data == elem) {
        AddToHead(head, data);
    }
    else {
        Node* p = head;
        while (p->next) {
            if (p->next->data == elem) {
                AddAfterElem(p,data);
                break;
            }
            p = p->next;
        }
    }
}


void DeleteFromHead(Node*& head) {
    if (head) {
        Node* pDel = head;
        head = head->next;
        delete pDel;
        pDel = nullptr;
    }
}

void DeleteAfterElem(Node* head, int elem) {
    Node* p = head;
    while (p) {
        if (p->data == elem && p->next) {
            DeleteAfterElem(p);
            break;
        }
        p = p->next;
    }
}

void DeleteAfterElem(Node* ptr) {
    if (ptr && ptr->next) {
        Node* pDel = ptr->next;
        ptr->next = ptr->next->next;
        delete pDel;
        pDel = nullptr;
    }
}

void DeleteAllOccurrences(Node*& head, int data) {
    while (head && head->data == data) {
        DeleteFromHead(head);
    }

    if (head) {
        Node* p = head;
        while (p->next) {
            if (p->next->data == data) {
                DeleteAfterElem(p);
            }
            else {
                p = p->next;
            }
        }
    }
}

void ShowList(Node* head) {
    Node* p = head;
    while (p) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

Node* SearchInList(Node* head, int data) {
    Node* p = head;
    while (p) {
        if (p->data == data) {
            return p;
        }
        
        p = p->next;
    }
    return nullptr;
}
bool isEmpty(Node* head) {
    return head == nullptr;
}
Node* removeDuplicates(Node* head) {
    if (!head)
        return nullptr;

    Node* p = head;
    while (p && p->next) {
        if (p->data == p->next->data) {
            DeleteAfterElem(p);
        }
        else {
            p = p->next;
        }
    }
    return head;
}