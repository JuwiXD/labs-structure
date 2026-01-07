#include "DoubleList.h"

int main() {
    setlocale(0, "");
    DList* list = new DList();


    std::cout << "\nЗАДАНИЕ 1: Самый частый диагноз\n";
    createFromFile(list, "sickleaves.txt");
    auto cmp1 = [](const SickLeave& a, const SickLeave& b) {
        return a.illness < b.illness;
        };
    sort(list, cmp1);
    Task1_MostCommonIllness(list);
    clear(list);

    std::cout << "\nЗАДАНИЕ 2: Удалить больничные позднее 15.03.2025\n";
    createFromFile(list, "sickleaves.txt");
    auto cmp2 = [](const SickLeave& a, const SickLeave& b) {
        if (a.year != b.year) return a.year > b.year;
        if (a.month != b.month) return a.month > b.month;
        return a.day > b.day;
        };
    sort(list, cmp2);
    std::cout << "До удаления:\n";
    show(list);
    Task2_DeleteAfterDate(list, 15, 3, 2025);
    std::cout << "\nПосле удаления:\n";
    show(list);
    clear(list);

    std::cout << "\nЗАДАНИЕ 4: Макс. дни в Сбербанк\n";
    createFromFile(list, "sickleaves.txt");
    auto cmp4 = [](const SickLeave& a, const SickLeave& b) {
        if (a.workplace != b.workplace)
            return a.workplace < b.workplace;
        return a.daysOff > b.daysOff;
        };
    sort(list, cmp4);
    Task4_MaxDaysForCompany(list, "Сбербанк");

    clear(list);
    delete list;
    return 0;
}