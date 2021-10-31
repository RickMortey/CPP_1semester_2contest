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
/// @brief builds heap with restoring the main heap property
///
void Heap::BuildHeap() {
    for (int i = heapSize / 2; i >= 1; --i) {
        siftDown(i);
    }
}

///
/// @brief sorts the given array using
///
/// param[in] beg - pointer to begin of the array
///
/// param[im] end - pointer to the end of the array
///
void HeapSort(int* beg, int* end) {
    Heap heap;
    heap.a = beg;
    heap.heapSize = end - beg;
    heap.BuildHeap();
    for (int i = heap.heapSize; i >= 2; --i) {
        std::swap(heap.a[1], heap.a[i]);
        heap.heapSize = heap.heapSize - 1;
        heap.siftDown(1);
    }
}

int main() {
    int sizeOfHeap;
    std::cin >> sizeOfHeap;
    int* a = new int[sizeOfHeap + 1];
    a[0] = 2147483647; // 2^31 - 1

    for (int i = 1; i <= sizeOfHeap; ++i) {
        std::cin >> a[i];
    }

    int* beg = a;
    int* end = a + sizeOfHeap;
    
    HeapSort(beg, end);

    for (int i = 1; i <= sizeOfHeap; ++i) {
        std::cout << a[i] << ' ';
    }

    delete[] a;
}