#include <iostream>

///
/// @brief partitions given array into two parts: <= pivot and >= pivot
///
/// @return index between parts < pivot and >= pivot
///
int Hoarepartition(int* beg, int* end) {
    int pivot = beg[(end - beg) / 2];
    int i = 0;
    int j = end - beg;
    while (i <= j) {
        while (beg[i] < pivot) {
            i++;
        }
        while (beg[j] > pivot) {
            j--;
        }
        if (i >= j) {
            break;
        }
        std::swap(beg[i++], beg[j--]);
    }
    return j;
}

///
/// @brief recurrent function which sorts given array,
/// splitting it into two parts: a[0...divider] and a[divider+1...n-1]
/// which have been transformed to ones less and bigger than pivot
///
void quicksort(int* beg, int* end) {
    if (end - beg > 0) {
        int q = Hoarepartition(beg, end);
        quicksort(beg, &beg[q]);
        quicksort(&beg[q + 1], end);
    }
}

int main() {

    int size;
    std::cin >> size;

    int* a = new int[size];
    for (int i = 0; i < size; ++i) {
        std::cin >> a[i];
    }

    quicksort(a, a + size - 1);

    for (int i = 0; i < size; ++i) {
        std::cout << a[i] << ' ';
    }

    delete[] a;

    return 0;
}