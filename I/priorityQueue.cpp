#include <iostream>

///
/// @brief contains array a on which a heap is built
/// and also heapSize - size of heap
///
struct Heap
{
    // numeration starts from one
    int* a = nullptr;
    int heapSize = 0;

    bool isEmpty();
    int parent(int i);
    int left(int i);
    int right(int i);
    int siftUp(int i);
    int siftDown(int i);

    int erase(int i);
    int extractMax();
    int insert(int key);

    void BuildHeap();
    void HeapSort();
};

///
/// @brief checks whether heap empty or not
///
/// @return true if empty, otherwise false
///
bool Heap::isEmpty() {
    return(!(heapSize > 0));
}

///
/// @brief function created for better code understanding
///
/// @param[in] i is an index of the element whose parent we are looking for
///
/// @return parent of child with index i
///
int Heap::parent(int i) {
    return i / 2;
}

///
/// @brief function created for better code understanding
///
/// @param[in] i is an index of the element whose left child we are looking for
///
/// @return left child of parent with index i
///
int Heap::left(int i) {
    return 2 * i;
}

///
/// @brief function created for better code understanding
///
/// @param[in] i is an index of the element whose right child we are looking for
///
/// @return right child of parent with index i
///
int Heap::right(int i) {
    return 2 * i + 1;
}

///
/// @brief sifts down an element in heap.
/// Is simply changes element with its child if main heap rule is violated
/// (parent is less than child)
///
/// @param[in] i is an index of the element we are going to sift down
///
/// @return new index of the element we have sifted down
///
int Heap::siftDown(int i) {
    int newIndex;
    while (true) {
        int L = left(i);
        int R = right(i);
        int max;
        newIndex = i;
        if (L <= heapSize && a[L] > a[i]) {
            max = L;
        }
        else {
            max = i;
        }
        if (R <= heapSize && a[R] > a[max]) {
            max = R;
        }

        if (max != i) {
            std::swap(a[i], a[max]);
            i = max;
            newIndex = i;
        }
        else {
            break;
        }
    }
    return newIndex;

}

///
/// @brief sifts up an element in heap.
/// Is simply changes element with its child if main heap rule is violated
/// (child is bigger than parent)
///
/// @param[in] i is an index of the element we are going to sift up
///
/// @return new index of the element we have sifted up
///
int Heap::siftUp(int i) {
    int newIndex = i;
    while (parent(i) >= 1 && a[i] >= a[parent(i)]) {
        if (a[i] > a[parent(i)]) {
            std::swap(a[parent(i)], a[i]);
            i = i / 2;
        }
        else if (a[parent(i)] == a[i]) {
            break;
        }
        newIndex = i;
    }

    return newIndex;
}

///
/// @brief deletes element with index i from heap
///
/// @param[in] i - index of the element in heap we are going to delete
///
/// @return deleted element
///
int Heap::erase(int i) {
    int answer = a[i];
    a[i] = a[heapSize--];
    if (a[i] >= a[parent(i)]) {
        siftUp(i);
    }
    else {
        siftDown(i);
    }
    return answer;
}

///
/// @brief deletes the biggest element from heap
///
/// @return index of the element a[heapsize] 
/// which have been placed instead of a[1]
/// after sifting it down (restoring the main heap property)
///
int Heap::extractMax() {
    int newIndex = -1;
    if (heapSize >= 2) {
        a[1] = a[heapSize];
        --heapSize;
        newIndex = siftDown(1);
    }
    else if (heapSize == 1) {
        --heapSize;
        newIndex = 0;
    }
    return newIndex;
}

///
/// @brief inserts element in heap
///
/// @return index of the inserted element
/// after restoring the main heep property
///
int Heap::insert(int key) {
    a[++heapSize] = key;
    int newIndex = siftUp(heapSize);
    return newIndex;
}

void Heap::BuildHeap() {
    for (int i = heapSize / 2; i >= 1; --i) {
        siftDown(i);
    }
}

void Heap::HeapSort() {
    BuildHeap();
    for (int i = heapSize; i >= 2; --i) {
        std::swap(a[1], a[i]);
        heapSize = heapSize - 1;
        siftDown(1);
    }
}

int main() {
    int maxSizeOfHeap, requestsQuantity;
    std::cin >> maxSizeOfHeap >> requestsQuantity;
    Heap heap;
    heap.a = new int[maxSizeOfHeap + 1];
    heap.heapSize = 0;
    heap.a[0] = 2147483647; // 2^31 - 1

    for (int i = 0; i < requestsQuantity; ++i) {
        char request;
        std::cin >> request;
        if (request == '1') {
            if (heap.isEmpty()) {
                std::cout << "-1\n";
            }
            else {
                int extractedMax = heap.a[1];
                int newIndex = heap.extractMax();
                std::cout << newIndex << ' ' << extractedMax << '\n';
            }
        }
        else if (request == '2') {
            int key;
            std::cin >> key;
            int newIndex;
            if (heap.heapSize < maxSizeOfHeap) {
                newIndex = heap.insert(key);
            }
            else {
                newIndex = -1;
            }
            std::cout << newIndex << '\n';
        }
        else if (request == '3') {
            int index;
            std::cin >> index;
            if (index < 1 || index > heap.heapSize) {
                std::cout << "-1\n";
            }
            else {
                int deletedValue = heap.erase(index);
                std::cout << deletedValue << '\n';
            }
        }
    }

    for (int i = 1; i <= heap.heapSize; ++i) {
        std::cout << heap.a[i] << ' ';
    }

    delete[] heap.a;
    heap.a = nullptr;
    heap.heapSize = 0;
}