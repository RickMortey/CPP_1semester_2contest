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

///
/// @brief checks who is the winner
///
/// @return true is first player has won, otherwise false
///
bool isFirstWon(int firstFront, int secondFront) {

    if (firstFront == 0 && secondFront == 9) {
        return true;
    }
    else if (firstFront == 9 && secondFront == 0) {
        return false;
    }
    else if (firstFront > secondFront) {
        return true;
    }
    else {
        return false;
    }
}

int main() {

    List first, second;

    for (int i = 0; i < 5; ++i) {
        int data;
        std::cin >> data;
        first.push_back(data);
    } 

    for (int i = 0; i < 5; ++i) {
        int data;
        std::cin >> data;
        second.push_back(data);
    }

    int turn = 0;
    bool isBotva = false;

    ///
    /// @brief player loses if the opponent has no cards. Let's check it.
    ///
    /// @note In my deque realization pop_back & pop_front returns an integer
    ///
    while (!first.isEmpty() && !second.isEmpty()) {

        if (turn == 1000000) {
            isBotva = true;
            std::cout << "botva\n";
            break;
        }

        if (isFirstWon(first.front(), second.front())) { 
            // first won
            first.push_back(first.pop_front());
            first.push_back(second.pop_front());
        }
        else {
            // second won
            second.push_back(first.pop_front());
            second.push_back(second.pop_front());
        }

        ++turn;

    }

    if (!isBotva) {
        if (first.isEmpty()) {
            std::cout << "second" << ' ' << turn;
        }
        else {
            std::cout << "first" << ' ' << turn;
        }
    }

    first.clear();
    second.clear();

    return 0;
}