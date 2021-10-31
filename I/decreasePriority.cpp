//#include <iostream>
//
//
//struct Heap
//{
//    // numeration starts from one
//    int* a = nullptr;
//    int heapSize = 0;
//
//    int parent(int i) {
//        return i / 2;
//    }
//
//    int left(int i) {
//        return 2 * i;
//    }
//    int right(int i) {
//        return 2 * i + 1;
//    }
//
//    void BuildHeap() {
//        for (int i = heapSize / 2; i >= 1; --i) {
//            siftDown(i);
//        }
//    }
//
//    bool isEmpty() {
//        return(!(heapSize > 0));
//    }
//
//    //void siftDown(int i);
//    int siftUp(int i);
//    int siftDown(int i);
//
//    void HeapSort() {
//        BuildHeap();
//        for (int i = heapSize; i >= 2; --i) {
//            std::swap(a[1], a[i]);
//            heapSize = heapSize - 1;
//            siftDown(1);
//        }
//    }
//};
//
//int Heap::siftDown(int i) {
//    int newIndex;
//    while (true) {
//        int L = left(i);
//        int R = right(i);
//        int max;
//        newIndex = i;
//        if (L <= heapSize && a[L] > a[i]) {
//            max = L;
//        }
//        else {
//            max = i;
//        }
//        if (R <= heapSize && a[R] > a[max]) {
//            max = R;
//        }
//
//        if (max != i) {
//            std::swap(a[i], a[max]);
//            i = max;
//            newIndex = i;
//        }
//        else {
//            break;
//        }
//    }
//    return newIndex;
//
//}
//
//int Heap::siftUp(int i) {
//    int P = parent(i);
//    int newIndex = i;
//    while (parent(i) >= 1 && a[i] >= a[parent(i)]) {
//        if (a[i] > a[parent(i)]) {
//            std::swap(a[parent(i)], a[i]);
//        }
//        i = i / 2;
//        newIndex = i;
//    }
//
//    return newIndex;
//}
//
//int main() {
//    int sizeOfHeap;
//    std::cin >> sizeOfHeap;
//    Heap heap;
//    heap.a = new int[sizeOfHeap + 1];
//    heap.heapSize = sizeOfHeap;
//    heap.a[0] = 2147483647;
//    for (int i = 1; i <= sizeOfHeap; ++i) {
//        int key;
//        std::cin >> key;
//        heap.a[i] = key;
//    }
//    int numberOfRequests;
//    std::cin >> numberOfRequests;
//
//    for (int i = 0; i < numberOfRequests; ++i) {
//        int index, key;
//        std::cin >> index >> key;
//        heap.a[index] -= key;
//        int newIndex = heap.siftDown(index);
//        std::cout << newIndex << '\n';
//    }
//
//    for (int i = 1; i <= heap.heapSize; ++i) {
//        std::cout << heap.a[i] << ' ';
//    }
//
//    delete[] heap.a;
//    heap.a = nullptr;
//}