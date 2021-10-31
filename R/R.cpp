#include<iostream>

///
/// @brief partitions given array into two parts: < pivot and >= pivot
///
/// @return index between parts < pivot and >= pivot
///
int partition(int*& a, int left, int right) {
    int x = a[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (a[j] <= x) {
            ++i;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[right]);
    return i + 1;
}

///
/// @brief recurrent function which sorts given array,
/// splitting it into two parts: a[0...pivot] and a[pivot+1...n-1]
/// which have been transformed to ones less and bigger than pivot
///
void quickSort(int*& a, int left, int right) {
    int pivot;
    if (left < right) {
        pivot = partition(a, left, right);
        quickSort(a, left, pivot - 1);
        quickSort(a, pivot + 1, right);
    }
}

///
/// @brief finds min between two numbers
///
/// @param[in] a, b - numbers where min must be found
///
/// @return min of two numbers
///
int min(int a, int b) {
    if (a > b) {
        return b;
    }
    else {
        return a;
    }
}

int main() {
    int n;
    std::cin >> n;
    int* arr = new int[n];
    int* lengths = new int[n + 1];

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    lengths[0] = 0;
    lengths[1] = 0;
    lengths[2] = arr[1] - arr[0];
    ///
    /// choose between connecting with next and connecting with prev
    ///
    if (n > 2) {
        lengths[3] = arr[2] - arr[0];
    }
    for (int i = 4; i < n + 1; ++i) {
        lengths[i] = min(lengths[i - 1], lengths[i - 2])
            + arr[i - 1] - arr[i - 2];
    }

    std::cout << lengths[n];

    delete[] lengths;
    delete[] arr;
    return 0;
}