#pragma once
#include <iostream>
#include <string>
#include <functional>
#include <fstream>

struct SickLeave {
    std::string fullName;
    std::string workplace;
    int illness;
    int day, month, year;
    int daysOff;

    bool operator==(const SickLeave& other) const {
        return fullName == other.fullName &&
            workplace == other.workplace &&
            illness == other.illness &&
            day == other.day &&
            month == other.month &&
            year == other.year &&
            daysOff == other.daysOff;
    }

    bool operator!=(const SickLeave& other) const {
        return !(*this == other);
    }
};

struct Node {
    SickLeave* data;
    Node* next;
    Node* prev;
    Node(SickLeave* _data = nullptr) : data(_data), next(nullptr), prev(nullptr) {}
};

struct DList {
    Node* head;
    Node* tail;
    DList() : head(nullptr), tail(nullptr) {}
};

void clear(DList*& list);
bool isEmpty(DList* list);
void show(DList* list);
void createFromFile(DList*& list, const std::string& filename);


void AddToTail(DList*& list, SickLeave* data);
void addToHead(DList*& list, SickLeave* data);
void addAfterElem(DList*& list, SickLeave* elem, SickLeave* data);
void addAfterElem(DList*& list, Node* ptr, SickLeave* data);
void addBeforeElem(DList*& list, SickLeave* elem, SickLeave* data);
void addBeforeElem(DList*& list, Node* ptr, SickLeave* data);


void DeleteFromTail(DList*& list);
void DeleteFromHead(DList*& list);
void deleteElem(DList*& list, Node* ptr);
void removeAfterElem(DList*& list, SickLeave* elem);
void removeAfterElem(DList*& list, Node* ptr);
void removeBeforeElem(DList*& list, SickLeave* elem);
void removeBeforeElem(DList*& list, Node* ptr);


void sort(DList* list, std::function<bool(const SickLeave&, const SickLeave&)> compare);
void Task1_MostCommonIllness(DList* list);
void Task2_DeleteAfterDate(DList*& list, int day, int month, int year);
void Task4_MaxDaysForCompany(DList* list, const std::string& companyName);