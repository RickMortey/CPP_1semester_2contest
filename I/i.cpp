//#include <iostream>
//
//
//struct Heap
//{
//    // numeration starts from one
//    int* a = nullptr;
//    int length = 0;
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
//    bool isEmpty() {
//        return(!(length - 1 > 0));
//    }
//
//    void siftDown(int i);
//    void siftUp(int i);
//
//    void BuildHeap() {
//        for (int i = length / 2; i >= 1; --i) {
//            siftDown(i);
//        }
//    }
//    
//    bool extractMax(int& max, int& index) {
//        if (isEmpty()) {
//            index = -1;
//            return false;
//        }
//        else {
//            max = a[1];
//            --length;
//            if (isEmpty()) {
//                index = 0;
//                return true;
//            }
//            else {
//                a[1] = a[length];
//                siftDown(1);
//            }
//        }
//    }
//
//    void HeapSort() {
//        BuildHeap();
//        for (int i = length; i >= 2; --i) {
//            std::swap(a[1], a[i]);
//            length = length - 1;
//            siftDown(1);
//        }
//    }
//};
//
//void Heap::siftDown(int i) {
//    while (true) {
//        int L = left(i);
//        int R = right(i);
//        int max;
//        if (L <= length && a[L] > a[i]) {
//            max = L;
//        }
//        else {
//            max = i;
//        }
//        if (R <= length && a[R] > a[max]) {
//            max = R;
//        }
//
//        if (max != i) {
//            std::swap(a[i], a[max]);
//            siftDown(max);
//        }
//        else {
//            
//        }
//    }
//
//}
//
//void Heap::siftUp(int i) {
//    int P = parent(i);
//
//    if (P >= 1 && a[i] > a[P]) {
//        std::swap(a[P], a[i]);
//        siftUp(P); // call parent index where we keep a[i]
//    }
//    else if (P >= 1 && a[i] == a[P]) {
//        siftUp(P);
//    }
//}
//
//int main() {
//    int n;
//    std::cin >> n;
//    int* a = new int[n + 1];
//    a[0] = 2147483647; // 2^31 - 1 = +inf
//    for (int i = 1; i < n + 1; ++i) {
//        std::cin >> a[i];
//    }
//
//    Heap heap;
//    heap.a = a;
//    heap.length = n;
//    for (int i = 1; i < n + 1; ++i) {
//        std::cout << heap.a[i] << ' ';
//    }
//    std::cout << '\n';
//    heap.HeapSort();
//    for (int i = 1; i < n + 1; ++i) {
//        std::cout << heap.a[i] << ' ';
//    }
//    delete[] heap.a;
//    heap.a = nullptr;
//}