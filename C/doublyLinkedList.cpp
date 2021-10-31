#include <iostream>
#include <string.h>

///
/// @brief Node struct contains key and pointers to next and prev Nodes
///
struct Node {
    int key = 0;
    Node* ptr_next = 0;
    Node* ptr_prev = 0;
};
///
/// @brief here List modified to doubly linked list with standart methods
/// List contains size and pointers to first and last element of deque
///
struct List {
    Node* beg = nullptr;
    Node* end = nullptr;
    int size = 0;
    void push_back(int key);
    void push_front(int key);
    int pop_front();
    int pop_back();
    bool isEmpty();
    int front();
    int back();
    void clear();
};

///
/// @brief adds an element to the end of deque
///
/// @param[in] element which must be added
///
void List::push_back(int key) {
    Node* temp = new Node;
    temp->key = key;
    temp->ptr_next = nullptr;
    ++size;
    if (beg == nullptr) {
        temp->ptr_prev = nullptr;
        beg = end = temp;
        return;
    }
    end->ptr_next = temp;
    temp->ptr_prev = end;
    end = temp;
    return;
}

///
/// @brief adds an element to the begin of deque
///
/// @param[in] element which must be added
///
void List::push_front(int key) {
    Node* temp = new Node;
    temp->key = key;
    temp->ptr_prev = nullptr;
    ++size;
    if (beg == nullptr) {
        temp->ptr_next = nullptr;
        beg = end = temp;
        return;
    }
    beg->ptr_prev = temp;
    temp->ptr_next = beg;
    beg = temp; // побитово копирует адрес €чейки
    // (указатель указывает на другую €чейку, данные не тер€ем)
    //  => всЄ нормально, предыдущий end мы не потер€ли
    return;
}

///
/// @brief deletes last element of deque
///
/// @return key of the deleted element
///
int List::pop_back() {
    if (end == nullptr) {
        return -1;
    }
    Node* temp = end;
    end = end->ptr_prev;
    --size;
    int pop_key = temp->key;
    if (isEmpty()) {
        beg = end = nullptr;
    }
    else {
        end->ptr_next = nullptr;
    }
    delete temp; // We have to delete ptrs and this is ptr to Node
    return pop_key;
}

///
/// @brief deletes first element of deque
///
/// @return key of the deleted element
///
int List::pop_front() {
    if (beg == nullptr) {
        return -1;
    }
    Node* temp = beg;
    beg = beg->ptr_next;
    --size;
    int pop_key = temp->key;
    if (isEmpty()) {
        beg = end = nullptr;
    }
    else {
        beg->ptr_prev = nullptr;
    }
    delete temp;
    return pop_key;
}

///
/// @brief check whether the stack is empty or not
///
/// @return true if stack is empty, otherwise false
///
bool List::isEmpty() {
    return !(size > 0);
}

///
/// @brief return key of the first element of deque
/// 
/// @return key of the first element of deque
///
int List::front() {
    return beg->key;
}

///
/// @brief return key of last element of deque
/// 
/// @return key of last element of deque
///
int List::back() {
    return end->key;
}

///
/// @brief clears deque
///
/// @note while there are at least one element in deque, we pop it from back
///
void List::clear() {
    while (!isEmpty()) {
        pop_back();
    }
}


int main() {
    List r;
    while(true) {
        char command[15] = { 0 };
        std::cin >> command;
        if (!strcmp(command, "push_back")) {
            int value;
            std::cin >> value;
            r.push_back(value);
            std::cout << "ok\n";
        }
        else if (!strcmp(command, "push_front")) {
            int value;
            std::cin >> value;
            r.push_front(value);
            std::cout << "ok\n";
        }
        else if (!strcmp(command, "pop_back")) {
            if (!r.isEmpty()) {
                std::cout << r.pop_back() << '\n';
            }
            else {
                std::cout << "error\n";
            }
        }
        else if (!strcmp(command, "pop_front")) {
            if (!r.isEmpty()) {
                std::cout << r.pop_front() << '\n';
            }
            else {
                std::cout << "error\n";
            }
        }
        else if (!strcmp(command, "front")) {
            if (!r.isEmpty()) {
                std::cout << r.front() << '\n';
            }
            else {
                std::cout << "error\n";
            }
        }
        else if (!strcmp(command, "back")) {
            if (!r.isEmpty()) {
                std::cout << r.back() << '\n';
            }
            else {
                std::cout << "error\n";
            }
        }
        else if (!strcmp(command, "size")) {
            std::cout << r.size << '\n';
        }
        else if (!strcmp(command, "clear")) {
            r.clear();
            std::cout << "ok\n";
        }
        else if (!strcmp(command, "exit")) {
            r.clear();
            std::cout << "bye\n";
            break;
        }
    }
    r.clear();
}