#include <iostream>
#include <string>
struct Node {
    int key = 0;
    Node* prev = nullptr;
    int min = 0; // min elem which have been added before this Node
};

struct stack {
    size_t size = 0;
    Node* top = nullptr;
    void push_back(int data);
    void pop_back();
    void clear();
    bool isEmpty();
    // void updateMin();
    // void push_min(int data)
};

bool stack::isEmpty() {
    return !(size > 0);
}

// compare mins on top 
// keep the lowest element on top->min

//void stack::updateMin() {
//
//    if (size == 1) {
//        top->min = top->key;
//        return;
//    }
//
//    if (!isEmpty()) {
//        top->min = (top->key < top->prev->min) ? top->key : top->prev->min;
//    }
//}

//void stack::push_back(int a) {
//    Node* tmp = new Node;
//    tmp->key = a;
//    if (isEmpty()) {
//        tmp->prev = nullptr;
//    }
//    else {
//        tmp->prev = top;
//    }
//    top = tmp;
//    ++size;
//    updateMin();
//}

void stack::push_back(int data) {
    Node* newNode = new Node;
    if (size == 0) {
        newNode->min = data;
    }
    else {
        if (data < top->min) {
            newNode->min = data;
        }
        else {
            newNode->min = top->min;
        }
        newNode->prev = top;
    }
    newNode->key = data;
    top = newNode;
    size++;
}



void stack::pop_back() { // deletes the last element
    if (!isEmpty()) {
        Node* oldtop = top;
        top = top->prev;
        delete oldtop;
        --size;
    }
}

void stack::clear() {
    while (!isEmpty()) {
        pop_back();
    }
}

struct queue {
    stack push;
    stack del;
    bool enqueue(int n);
    int dequeue();
    int front();
    size_t size();
    void clear();
    int min();
    bool isEmpty();
};

bool queue::isEmpty() {
    if (del.isEmpty() && push.isEmpty()) {
        return true;
    }
    else {
        return false;
    }
}
bool queue::enqueue(int n) {

    while (!del.isEmpty()) {
        push.push_back(del.top->key);
        del.pop_back();
    }

    push.push_back(n);

    return true;
}

int queue::dequeue() {
    while (!push.isEmpty()) {
        del.push_back(push.top->key);
        push.pop_back();
    }
    int ans = del.top->key;
    del.pop_back();
    return ans;
}

int queue::front() {
    while (!push.isEmpty()) {
        del.push_back(push.top->key);
        push.pop_back();
    }
    return del.top->key;
}

size_t queue::size() {
    size_t sizeAll = push.size + del.size;
    return sizeAll;
}

void queue::clear() {
    push.clear();
    del.clear();
}

int queue::min() {
    int min;
    if (del.isEmpty() && !push.isEmpty()) {
        min = push.top->min;
    }
    else if (!del.isEmpty() && push.isEmpty()) {
        min = del.top->min;
    }
    else {
        min = (del.top->min < push.top->min) ? del.top->min : push.top->min;
    }
    return min;
}


//int queue::min() {
//    while (!del.isEmpty()) {
//        push.push_back(del.top->key);
//        del.pop_back();
//    }
//    int ans = push.top->key;
//    push.pop_back();
//    for (size_t i = 0; i < size(); ++i) {
//        ans = (ans > push.top->key ? push.top->key : ans);
//        del.push_back(push.top->key);
//        push.pop_back();
//    }
//    return ans;
//}

void commands(queue& q, std::string& command) {
    switch (command[0]) { // due to first letter of each command is unique
    case 'e':
        int n;
        std::cin >> n;
        q.enqueue(n);
        std::cout << "ok\n";
        break;
    case 'd':
        if (!q.isEmpty()) {
            std::cout << q.dequeue() << '\n';
        }
        else {
            std::cout << "error\n";
        }
        break;
    case 'f':
        if (!q.isEmpty()) {
            std::cout << q.front() << '\n';
        }
        else {
            std::cout << "error\n";
        }
        break;
    case 's':
        std::cout << q.size() << '\n';
        break;
    case 'c':
        q.clear();
        std::cout << "ok\n";
        break;
    case 'm':
        if (!q.isEmpty()) {
            std::cout << q.min() << '\n';
        }
        else {
            std::cout << "error\n";
        }
        break;
    }
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int m;
    std::cin >> m;
    queue q;
    for (int i = 0; i < m; ++i) {
        std::string command;
        std::cin >> command;
        commands(q, command);
    }
    q.clear();
}