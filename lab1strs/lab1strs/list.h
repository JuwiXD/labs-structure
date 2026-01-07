#pragma once
#include<iostream>
#include <fstream>

struct Node {
    Node* next;
    int data;
    Node() {
        next = nullptr;
        data = 0;
    }
    Node(int _data, Node* _next = nullptr) {
        next = _next;
        data = _data;
    }
    ~Node() {
        next = nullptr;
    }
};

void createLikestack(Node*& head, std::istream& in = std::cin);
void createLikeQueue(Node*& head, std::istream& in = std::cin);



void AddToHead(Node*& head, int data); 
void AddAfterElem(Node* head, int data, int elem);
void AddAfterElem(Node* ptr, int data);
void AddBeforeElem(Node*& head, int data, int elem);

void DeleteFromHead(Node*& head);
void DeleteAfterElem(Node* head, int elem);
void DeleteAfterElem(Node* ptr);
void DeleteAllOccurrences(Node*& head, int data);

void ShowList(Node* head);
Node* SearchInList(Node* head, int data);
bool isEmpty(Node* head);
Node* removeDuplicates(Node* head);