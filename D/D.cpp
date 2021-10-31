#include <iostream>


///
/// @brief Node contains key of the element 
/// and pointer to the previous one in stack
///
struct Node {
    int key = 0;
    Node* prev = nullptr;
};

///
/// @brief stack contains pointer to top element and size
///
/// @note methods will be described separately
///
struct stack {
    size_t size = 0;
    Node* top = nullptr;
    void push_back(int a);
    void pop_back();
    void clear();
    bool isEmpty();
    void op(char in);
    int Top();
};

///
/// @brief function created to increase readability of the code
///
/// @return last element of list
///
int stack::Top() {
    return top->key;
}

///
/// @brief check whether the stack is empty or not
///
/// @return true if stack is empty, otherwise false
///
bool stack::isEmpty() {
    return !(size > 0);
}

///
/// @brief adds an element to the end of stack
///
/// @param[in] element which must be added
///
void stack::push_back(int a) {
    Node* tmp = new Node;
    tmp->key = a;
    if (isEmpty()) {
        tmp->prev = nullptr;
    }
    else {
        tmp->prev = top;
    }
    top = tmp;
    ++size;
}

///
/// @brief deletes the last element
///
/// @note does nothing if stack is empty
///
void stack::pop_back() { // deletes the last element
    if (!isEmpty()) {
        Node* oldtop = top;
        top = top->prev;
        delete oldtop;
        --size;
    }
}

/// 
/// @brief deletes every element of stack
///
void stack::clear() {
    while (!isEmpty()) {
        pop_back();
    }
}

///
/// @brief changes two last elements of stack with its sum/diff/multiplication
///
void stack::op(char in) {
    int b = Top();
    pop_back();
    int a = Top();
    pop_back();
    switch (in) {
    case '+':
        push_back(a + b);
        break;
    case '-':
        push_back(a - b);
        break;
    case '*':
        push_back(a * b);
        break;
    }
}

///
/// @brief checks whether char element is digit or not
///
/// @return true if element is a digit, otherwise false
///
bool isNum(char in) {
    if (static_cast<int>(in) - 48 <= 9 && static_cast<int>(in) - 48 >= 0) {
        return true;
    }
    else {
        return false;
    }
}

///
/// @brief transfroms char (if isNum(in) == true)to digit
///
/// @return int digit made from char digit
///
int num(char in) {
    return static_cast<int>(in) - 48;
}


int main() {
    char in;
    stack s;
    while (std::cin >> in) {
        if (isNum(in)) {
            s.push_back(num(in));
        }
        else {
            s.op(in);
        }
    }
    std::cout << s.Top();
}