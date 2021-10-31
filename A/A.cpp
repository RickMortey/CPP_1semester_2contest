#include <iostream>
#include <string.h>

///
/// @brief Node contains key of the element 
/// and pointer to the previous one in stack
///
struct Node {
    char key = 0;
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
    void push_back(char a);
    void pop_back();
    void clear();
    bool isEmpty();
};

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
void stack::push_back(char a) {
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
void stack::pop_back() {
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
/// @brief depending on input bracket looks for opposite one
///
/// @param[in] closing bracket
///
/// @return bracket, opposite to the one inputted
///
char rev(char br) {
    if (br == '}') {
        return '{';
    }
    if (br == ')') {
        return '(';
    }
    if (br == ']') {
        return '[';
    }
    return ' ';
}

/// 
/// @brief decides if bracket sequence is right bracket sequence
///
/// @param[in] str - string we are supposed to read
/// 
/// @param[in] n - size of string str
///
/// @return true is bracket is right, otherwise false
///
bool isRBS(const char* str, size_t n) {
    stack s;
    char elem;

    for (size_t i = 0; i < n; ++i) {
        elem = str[i];
        if (elem == '(' || elem == '[' || elem == '{') {
            s.push_back(elem);
            continue;
        }

        if (s.isEmpty()) {
            s.clear();
            return false;
        }
        else if (rev(elem) == s.top->key) {
            s.pop_back();
        }
        else {
            s.clear();
            return false;
        }
    }

    if (s.isEmpty()) {
        s.clear();
        return true;
    }
    else {
        s.clear();
        return false;
    }
    
}


int main() {
    size_t size = 100000;
    char* str = new char[size];
    std::cin >> str;
    size_t n = strlen(str);
    if (isRBS(str, n)) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }
    delete[] str;
    return 0;

}   