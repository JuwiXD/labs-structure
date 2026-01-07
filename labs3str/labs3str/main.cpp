#include "stack.h"
#include "queue.h"
#include <iostream>

int main() {
    setlocale(0, "");


    TStack<double> st;
    st.push(3.14);
    st.push(155);
    std::cout << "Ёлемент сверху: " << st.peek() << std::endl;
    st.pop();
    std::cout << "Ёлемент сверху после pop: " << st.peek() << std::endl;
    st.push(15);
    st.push(20.5);
    st.clear();

    TQueue<char> que;
    que.enque('a');
    que.enque('1');
    que.enque('Z');
    que.enque('j');
    std::cout << "Ёлемент в начале очереди: " << que.peak() << std::endl;
    que.deque();
    std::cout << "Ёлемент в начале очереди после удалени€: " << que.peak() << std::endl;
    que.clear();

    return 0;
}