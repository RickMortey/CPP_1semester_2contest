#include <iostream>
#include <string.h>



struct Heap
{

    struct Node {
        int key;
        int number;
    };

    // numeration starts from one
    Node* a = nullptr;
    int heapSize = 0;
    int currentNumber = 1;

    void allocate(int maxSize);
    void deallocate();
    int parent(int i);
    int left(int i);
    int right(int i);
    int siftUp(int i);
    int siftDown(int i);
    bool isEmpty();
    bool isNumberInHeap(int number, int& index);

    void insert(int value);
    int extractMin();
    void erase(int number);
    void change(int value, int number);
    void clear();
};

void Heap::allocate(int size) {
    int maxSize = size;
    a = new Node[maxSize + 1];
    a[0].key = 2147483647; // 2^31 - 1
    a[0].number = -1;
}

void Heap::deallocate() {
    delete[] a;
    a = nullptr;
    heapSize = 0;
    currentNumber = 1;
}

void Heap::clear() {
    int limit = heapSize;
    for (int i = 1; i <= limit; ++i) {
        extractMin();
    }
}
bool Heap::isEmpty() {
    return(!(heapSize > 0));
}

int Heap::parent(int i) {
    return i / 2;
}

int Heap::left(int i) {
    return 2 * i;
}

int Heap::right(int i) {
    return 2 * i + 1;
}

int Heap::siftDown(int i) {
    int newIndex;
    while (true) {
        int L = left(i);
        int R = right(i);
        int min;
        newIndex = i;
        if (L <= heapSize && a[L].key < a[i].key) {
            min = L;
        }
        else {
            min = i;
        }
        if (R <= heapSize && a[R].key < a[min].key) {
            min = R;
        }

        if (min != i) {
            std::swap(a[i], a[min]);
            i = min;
            newIndex = i;
        }
        else {
            break;
        }
    }
    return newIndex;

}

int Heap::siftUp(int i) {
    int newIndex = i;
    while (parent(i) >= 1 && a[i].key <= a[parent(i)].key) {
        if (a[i].key < a[parent(i)].key) {
            std::swap(a[parent(i)], a[i]);
            i = i / 2;
        }
        else if (a[parent(i)].key == a[i].key) {
            break;
        }
        newIndex = i;
    }

    return newIndex;
}

void Heap::erase(int i) {
    a[i] = a[heapSize--];
    siftDown(i);
    siftUp(i);
}

int Heap::extractMin() {
    int extractedMin = a[1].key;
    if (heapSize >= 2) {
        a[1] = a[heapSize];
        --heapSize;
        siftDown(1);
    }
    else if (heapSize == 1) {
        --heapSize;
    }
    return extractedMin;
}

void Heap::insert(int value) {
    a[++heapSize].key = value;
    a[heapSize].number = currentNumber++;
    siftUp(heapSize);
}

bool Heap::isNumberInHeap(int number, int& index) {
    bool isNumberInHeap = false;
    for (int i = 1; i <= heapSize; ++i) {
        if (number == a[i].number) {
            isNumberInHeap = true;
            index = i;
            break;
        }
    }
    return isNumberInHeap;
}

void Heap::change(int index, int value) {
    a[index].key = value;
    siftDown(index);
    siftUp(index);
}

void requestHandling(char* request, Heap& heap) {
    if (!strcmp(request, "insert")) {
        int n;
        std::cin >> n;
        heap.insert(n);
        std::cout << "ok\n";
    }
    else if (!strcmp(request, "extract_min")) {
        if (heap.isEmpty()) {
            std::cout << "error\n";
        }
        else {
            std::cout << heap.extractMin() << '\n';
        }
    }
    else if (!strcmp(request, "get_min")) {
        if (heap.isEmpty()) {
            std::cout << "error\n";
        }
        else {
            std::cout << heap.a[1].key << '\n';
        }
    }
    else if (!strcmp(request, "size")) {
        std::cout << heap.heapSize << '\n';
    }
    else if (!strcmp(request, "clear")) {
        heap.heapSize = 0;
        std::cout << "ok\n";
        // we still need allocated memory, so we don't actually clean it
        // though we can use this memory to keep new elements
    }
    else if (!strcmp(request, "delete")) {
        int x;
        std::cin >> x;
        int index;
        if (heap.isNumberInHeap(x, index)) {
            heap.erase(index);
            std::cout << "ok\n";
        }
        else {
            std::cout << "error\n";
        }
    }
    else if (!strcmp(request, "change")) {
        int x;
        std::cin >> x;
        int newValue;
        std::cin >> newValue;
        int index;
        if (heap.isNumberInHeap(x, index)) {
            heap.change(index, newValue);
            std::cout << "ok\n";
        }
        else {
            std::cout << "error\n";
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int requestsQuantity;
    std::cin >> requestsQuantity;
    Heap heap;
    heap.allocate(requestsQuantity);
    // obviously, heapsize <= requestsQuantity
    char* request = new char[100];
    for (int i = 0; i < requestsQuantity; ++i) {
        std::cin >> request;
        requestHandling(request, heap);
    }

    heap.deallocate();
}