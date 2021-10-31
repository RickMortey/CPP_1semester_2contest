#include <iostream>

struct Rect {
    int x = 0;
    int y = 0;
};

#include <iostream>

struct Heap
{
    // numeration starts from one
    int* a = nullptr;
    int heapSize = 0;

    int parent(int i) {
        return i / 2;
    }

    int left(int i) {
        return 2 * i;
    }
    int right(int i) {
        return 2 * i + 1;
    }

    int siftUp(int i);
    int siftDown(int i);

    int erase(int i) {
        int answer = a[i];
        a[i] = a[heapSize--];
        if (a[i] <= a[parent(i)]) {
            siftUp(i);
        }
        else {
            siftDown(i);
        }
        return answer;
    }

    int extractMin() {
        int newIndex;
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

    int insert(int key) {
        a[++heapSize] = key;
        int newIndex = siftUp(heapSize);
        return newIndex;
    }

    void BuildHeap() {
        for (int i = heapSize / 2; i >= 1; --i) {
            siftDown(i);
        }
    }

    bool isEmpty() {
        return(!(heapSize > 0));
    }

    void HeapSort() {
        BuildHeap();
        for (int i = heapSize; i >= 2; --i) {
            std::swap(a[1], a[i]);
            heapSize = heapSize - 1;
            siftDown(1);
        }
    }
};

int Heap::siftDown(int i) {
    int newIndex;
    while (true) {
        int L = left(i);
        int R = right(i);
        int max;
        newIndex = i;
        if (L <= heapSize && a[L] < a[i]) {
            max = L;
        }
        else {
            max = i;
        }
        if (R <= heapSize && a[R] < a[max]) {
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

int Heap::siftUp(int i) {
    int newIndex = i;
    while (parent(i) >= 1 && a[i] <= a[parent(i)]) {
        if (a[i] < a[parent(i)]) {
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

int Hoarepartition(Rect* array, int l, int r) {
    int pivot = array[(l + r) / 2].y;
    int i = 0;
    int j = r;
    while (i <= j) {
        while (array[i].y > pivot) {
            i++;
        }
        while (array[j].y < pivot) {
            j--;
        }
        if (i >= j) {
            break;
        }
        std::swap(array[i++].y, array[j--].y);
    }
    return j;
}

void quicksort(Rect* array, int l, int r) {
    if (r - l > 0) {
        int q = Hoarepartition(array, l, r);
        quicksort(array, l, q);
        quicksort(array, q + 1, r);
    }
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int n, required;
    std::cin >> n >> required;
    Rect* rects = new Rect[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> rects[i].x >> rects[i].y;
    }

    quicksort(rects, 0, n-1);
    // sorting rects by y coord in decreasing
    for (int i = 0; i <= n; ++i) {
        std::cout << rects[i].x << rects[i].y;
    }
    long long maxS = 0;

}
