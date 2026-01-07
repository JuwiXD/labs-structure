#include <iostream>
#include "queue.h"


int main() {
    int N;
    std::cin >> N;

    TQueue<int> queue;

    for (int i = 0; i < N; ++i) {
        std::string command;
        std::cin >> command;

        if (command == "+") {
            int id;
            std::cin >> id;
            queue.enque(id);
        }
        else if (command == "*") {
            int id;
            std::cin >> id;
            queue.enque_middle(id);
        }
        else if (command == "-") {
            std::cout << queue.peak() << std::endl;
            queue.deque();
        }
    }

    return 0;
}
