#include <iostream>

// нумерация начинается не с 0, а с 1

int left(int i) {
    return 2 * i;
}

int right(int i) {
    return 2 * i + 1;
}

void siftDown(int* beg, int* end, int length, int i) {

    int L = left(i);
    int R = right(i);

    int max = i;

    if (L <= length && beg[L] > beg[i]) {
        max = L;
    }
    if (R <= length && beg[R] > beg[max]) {
        max = R;
    }

    if (max != i) {
        std::swap(beg[i], beg[max]);
        siftDown(beg, end, length, max);
    }
}

void buildHeap(int* beg, int* end, int length) {

    for (int i = length / 2; i >= 1; --i) {
        siftDown(beg, end, length, i);
    }
}

void heapSort(int* beg, int* end) {

    int length = end - beg + 1;

    buildHeap(beg, end, length);

    for (int i = length; i >= 2; --i) {
        std::swap(beg[1], beg[i]); // numeration starts from 1
        --length;
        siftDown(beg, end, length, 1);
    }
}



int main() {
    int size;
    std::cin >> size;

    int* arr = new int[size + 1];
    arr[0] = 0;
    // numeration starts from one for easy counting
    for (int i = 1; i <= size; ++i) {
        std::cin >> arr[i];
    }

    heapSort(&arr[1], &arr[1] + size - 1);

    for (int i = 1; i <= size; ++i) {
        std::cout << arr[i] << ' ';
    }

}