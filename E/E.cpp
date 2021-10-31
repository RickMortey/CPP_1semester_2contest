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
    beg = temp;
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
    delete temp;
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
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    List d1, d2;
    ///
    /// @brief d1 - end of the queue (closest to the witcher)
    /// d2 - begin of the queue
    /// keeping sizes d1 == d2 or sizes d + 1 == d2 after each iteration
    ///
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        char oper;
        std::cin >> oper;
        if (oper == '+') {
            int num;
            std::cin >> num;
            d2.push_back(num);
        }
        else if (oper == '*') {
            int num;
            std::cin >> num;
            d2.push_front(num);
        }
        else if (oper == '-') {
            std::cout << d1.pop_front() << '\n';
        }
        if (d2.size > d1.size) {
            d1.push_back(d2.front());
            d2.pop_front();
        }
    }
    d1.clear();
    d2.clear();
}