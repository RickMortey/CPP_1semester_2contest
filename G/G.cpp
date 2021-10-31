#include <iostream>


int* hoarePartition(int* beg, int* end) {
    int size = end - beg;
    int pivot = beg[size - 1];
    /*int* i = beg;
    int* j = end - 1;*/
    int i = 0;
    int j = size - 1;
    while (i <= j) {
        while (beg[i] < pivot) {
            ++i;
        }
        while (pivot < beg[j]) {
            --j;
        }
        if (i >= j) {
            break;
        }
        std::swap(beg[i], beg[j]);
        ++i;
        --j;
    }
    return beg + j;
}


void QuickSort(int *beg, int *end) {

    int size = (end - beg);
    if (size > 1) {
        int* divider = hoarePartition(beg, end);
        for (int i = 0; i < size; ++i) {
            std::cout << beg[i] << ' ';
        }
        std::cout << '\n';
        QuickSort(beg, divider + 1);
        QuickSort(divider + 1, end);
    }
}

int main() {

    int n;
    std::cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    QuickSort(arr, arr + n);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << ' ';
    }

    delete[] arr;
}