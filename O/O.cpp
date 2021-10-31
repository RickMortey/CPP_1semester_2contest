#include <iostream>

///
/// @brief merges two sorted arrays into one big sorted one
///
/// @param[in] a - first array
///
/// @param[in] sizeA - size of first array
///
/// @param[in] a - second array
///
/// @param[in] sizeA - size of second array
///
/// @return pointer to one big sorted array
/// which contains elements of given ones.
///
int* merge(int* a, int sizeA, int* b, int sizeB) {
    int it1 = 0;
    int it2 = 0;
    int* result = new int[sizeA + sizeB];

    while (it1 < sizeA && it2 < sizeB) {
        if (a[it1] < b[it2]) {
            result[it1 + it2] = a[it1];
            it1 += 1;
        }
        else {
            result[it1 + it2] = b[it2];
            it2 += 1;
        }
    }

    while (it1 < sizeA) {
        result[it1 + it2] = a[it1];
        it1 += 1;
    }

    while (it2 < sizeB) {
        result[it1 + it2] = b[it2];
        it2 += 1;
    }
    delete[] a;
    delete[] b;
    return result;
}

///
/// @brief outputs each element of the array separately
///
/// @param[in] res - array whose elements must be outputted
///
/// @param[in] sizeFin - size of the array
///
void arrOutput(int* res, int sizeFin) {
    for (int i = 0; i < sizeFin; ++i) {
        std::cout << res[i] << " ";
    }
}
///
/// @brief idea: we read 1st array, then read next, merge them into big array
/// merge big array with next one, etc...
///
int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int k;
    std::cin >> k;
    int sizeFin;
    std::cin >> sizeFin;
    int* res = new int[sizeFin];
    for (int i = 0; i < sizeFin; ++i) {
        std::cin >> res[i];
    }
    for (int i = 1; i < k; ++i) {
        int sizeIn;
        std::cin >> sizeIn;
        int* in = new int[sizeIn];
        for (int j = 0; j < sizeIn; ++j) {
            std::cin >> in[j];
        }
        res = merge(res, sizeFin, in, sizeIn);
        sizeFin += sizeIn;
    }
    arrOutput(res, sizeFin);
    delete[] res;
}