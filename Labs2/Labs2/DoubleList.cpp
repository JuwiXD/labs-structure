#include "DoubleList.h"

void show(DList* list) {
    if (isEmpty(list)) {
        std::cout << "Список пуст.\n";
        return;
    }
    Node* cur = list->head;
    while (cur) {
        std::cout << cur->data->fullName << " | "
            << cur->data->workplace << " | "
            << cur->data->illness << " | "
            << cur->data->day << "." << cur->data->month << "." << cur->data->year << " | "
            << cur->data->daysOff << " дн.\n";
        cur = cur->next;
    }
}

void clear(DList*& list) {
    while (list && list->head) {
        deleteElem(list, list->head);
    }
}

bool isEmpty(DList* list) {
    return !list || !list->head;
}

void addToHead(DList*& list, SickLeave* data) {
    Node* newNode = new Node(data);
    if (isEmpty(list)) {
        list->head = list->tail = newNode;
    }
    else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

void addAfterElem(DList*& list, Node* ptr, SickLeave* data) {
    if (!ptr || !list) 
        return;
    Node* newNode = new Node(data);
    newNode->prev = ptr;
    newNode->next = ptr->next;
    if (ptr->next) {
        ptr->next->prev = newNode;
    }
    else {
        list->tail = newNode;
    }
    ptr->next = newNode;
}


void addAfterElem(DList*& list, SickLeave* elem, SickLeave* data) {
    if (!list || !elem) return;
    Node* current = list->head;
    while (current) {
        if (*current->data == *elem) {
            addAfterElem(list, current, data);
            return;
        }
        current = current->next;
    }
}

void removeAfterElem(DList*& list, Node* ptr) {
    if (!ptr || !ptr->next || !list) return;
    Node* toDelete = ptr->next;
    ptr->next = toDelete->next;
    if (toDelete->next) {
        toDelete->next->prev = ptr;
    }
    else {
        list->tail = ptr;
    }
    delete toDelete->data;
    delete toDelete;
}


void removeAfterElem(DList*& list, SickLeave* elem) {
    if (!list || !elem) return;
    Node* current = list->head;
    while (current && current->next) {
        if (*current->data == *elem) {
            removeAfterElem(list, current);
            break;
        }
        current = current->next;
    }
}
void addBeforeElem(DList*& list, Node* ptr, SickLeave* data) {
    if (!ptr || !list) return;
    if (ptr == list->head) {
        addToHead(list, data);
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = ptr;
    newNode->prev = ptr->prev;
    ptr->prev->next = newNode;
    ptr->prev = newNode;
}


void addBeforeElem(DList*& list, SickLeave* elem, SickLeave* data) {
    if (!list || !elem) return;
    Node* current = list->head;
    while (current) {
        if (*current->data == *elem) {
            addBeforeElem(list, current, data);
            return;
        }
        current = current->next;
    }
}

void removeBeforeElem(DList*& list, Node* ptr) {
    if (!ptr || !ptr->prev || !list) return;
    Node* toDelete = ptr->prev;
    if (toDelete->prev) {
        toDelete->prev->next = ptr;
        ptr->prev = toDelete->prev;
    }
    else {
        list->head = ptr;
        ptr->prev = nullptr;
    }
    delete toDelete->data;
    delete toDelete;
}

void removeBeforeElem(DList*& list, SickLeave* elem) {
    if (!list || !elem) return;
    Node* current = list->head;
    while (current) {
        if (*current->data == *elem) {
            removeBeforeElem(list, current);
            return;
        }
        current = current->next;
    }
}
void AddToTail(DList*& list, SickLeave* data) {
    Node* newNode = new Node(data);

    if (isEmpty(list)) {
        list->head = newNode;
        list->tail = newNode;
    }
    else {
        list->tail->next = newNode;  
        newNode->prev = list->tail;  
        list->tail = newNode;        
    }
}
void DeleteFromHead(DList*& list) {
    if (!list || !list->head) return;

    Node* tmp = list->head;

    if (list->head == list->tail) {
        list->head = nullptr;
        list->tail = nullptr;
    }
    else {
        list->head = list->head->next;
        list->head->prev = nullptr;
    }

    delete tmp->data; 
    delete tmp;      
}
void DeleteFromTail(DList*& list) {
    if (!list || !list->tail) return; 

    Node* tmp = list->tail;

    if (list->head == list->tail) {
        
        list->head = nullptr;
        list->tail = nullptr;
    }
    else {
       
        list->tail = list->tail->prev;
        list->tail->next = nullptr;
    }

    delete tmp->data;
    delete tmp;
}
void deleteElem(DList*& list, Node* ptr) {
    if (!ptr || !list) return;
    if (ptr == list->head) {
        DeleteFromHead(list);
        return;
    }
    if (ptr == list->tail) {
        DeleteFromTail(list);
        return;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    delete ptr->data;
    delete ptr;
}


void createFromFile(DList*& list, const std::string& filename) {
    clear(list);

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл '" << filename << "'\n";
        return;
    }

    std::string surname, initials, workplace;
    int illness, day, month, year, daysOff;

    while (file >> surname >> initials >> workplace >> illness >> day >> month >> year >> daysOff) {
        std::string fullName = surname + " " + initials;
        SickLeave* sl = new SickLeave{ fullName, workplace, illness, day, month, year, daysOff };
        AddToTail(list, sl); 
    }

    file.close();
}

void sort(DList* list, std::function<bool(const SickLeave&, const SickLeave&)> compare) {
    if (isEmpty(list) || !list->head->next) {
        return;
    }
    auto swap = [](SickLeave* a, SickLeave* b) {
        SickLeave temp = *a;
        *a = *b;
        *b = temp;
        };

    bool swapped;
    Node* ptr;
    Node* lastPtr = nullptr;

    do {
        swapped = false;
        ptr = list->head;

        while (ptr->next != lastPtr) {
            if (compare(*ptr->next->data, *ptr->data)) {
                swap(ptr->data, ptr->next->data);
                swapped = true;
            }
            ptr = ptr->next;
        }
        lastPtr = ptr;
    } while (swapped);
}

void Task1_MostCommonIllness(DList* list) {
    if (!list || !list->head) {
        std::cout << "Список пуст.\n";
        return;
    }

    int curIll = list->head->data->illness;
    int curCnt = 1;
    int maxCnt = 1;
    int res = curIll;

    Node* cur = list->head->next;
    while (cur) {
        if (cur->data->illness == curIll) {
            curCnt++;
        }
        else {
            if (curCnt > maxCnt) {
                maxCnt = curCnt;
                res = curIll;
            }
            curIll = cur->data->illness;
            curCnt = 1;
        }
        cur = cur->next;
    }

    if (curCnt > maxCnt) {
        maxCnt = curCnt;
        res = curIll;
    }

    std::cout << "Наиболее частый диагноз (шифр): " << res << "\n";
}


void Task2_DeleteAfterDate(DList*& list, int day, int month, int year) {
    if (!list) return;

    while (list->head) {
        SickLeave* d = list->head->data;
        if (d->year > year ||
            (d->year == year && d->month > month) ||
            (d->year == year && d->month == month && d->day > day)) {
            DeleteFromHead(list);
        }
        else {
            break;
        }
    }
}

void Task4_MaxDaysForCompany(DList* list, const std::string& company) {
    if (!list || !list->head) {
        std::cout << "Список пуст.\n";
        return;
    }

    int maxDays = -1;
    Node* cur = list->head;
    bool found = false;
    while (cur) {
        if (cur->data->workplace == company) {
            found = true;
            if (cur->data->daysOff > maxDays) {
                maxDays = cur->data->daysOff;
            }
        }
        cur = cur->next;
    }

    if (!found) {
        std::cout << "Нет записей для предприятия: " << company << "\n";
        return;
    }

    std::cout << "Макс. дней нетрудоспособности в " << company << ": " << maxDays << "\n";
    std::cout << "Сотрудники:\n";
    cur = list->head;
    while (cur) {
        if (cur->data->workplace == company && cur->data->daysOff == maxDays) {
            std::cout << "  " << cur->data->fullName << "\n";
        }
        cur = cur->next;
    }
}