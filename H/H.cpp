#include <iostream>

int partition(int* a, int l, int r) {
    int pivot = a[rand() % (r - l + 1) + l];
    int i = l;
    int j = r;
    while (i <= j) {
        while (a[i] < pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i >= j) {
            break;
        }
        std::swap(a[i++], a[j--]);
    }
    return j;
}

void quicksort(int* a, int l, int r) {
    if (l < r) {
        int q = partition(a, l, r);
        quicksort(a, l, q);
        quicksort(a, q + 1, r);
    }
}

int value_of_k_ordered(int* a, int size, int k) {
    // due to numeration in the array starts from zero,
    // though ordering starts from one
    int left = 0;
    int right = size - 1;
    while (true) {

        int mid = partition(a, left, right);

        if (k == mid) {
            return a[mid];
        }
        else if (k < mid) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return a[k];
}

//void buildArray(int* a, int n) {
//    std::cin >> a[0];
//    std::cin >> a[1];
//    for (int i = 2; i < n; ++i) {
//        a[i] = ((a[i - 1] * 123 + a[i - 2] * 45) % (10004321));
//    }
//}
//
//int Hoarepartition(int* beg, int* end) {
//    int pivot = beg[(end - beg) / 2];
//    int i = 0;
//    int j = end - beg;
//    while (i <= j) {
//        while (beg[i] < pivot) {
//            i++;
//        }
//        while (beg[j] > pivot) {
//            j--;
//        }
//        if (i >= j) {
//            break;
//        }
//        std::swap(beg[i++], beg[j--]);
//    }
//    return j;
//}
//
//void quicksort(int* beg, int* end) {
//    if (end - beg > 0) {
//        int q = Hoarepartition(beg, end);
//        quicksort(beg, &beg[q]);
//        quicksort(&beg[q + 1], end);
//    }
//}


int main() {
    int n;
    std::cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    quicksort(a, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << ' ';
    }

    return 0;

    //buildArray(a, n);

    //for (int i = 0; i < n; ++i) {
    //    std::cout << a[i] << ' ';
    //}
    //std::cout << '\n';

    //quicksort(a, a + n - 1);
    //for (int i = 0; i < n; ++i) {
    //    std::cout << a[i] << ' ';
    //}
    //std::cout << '\n';
    
}
