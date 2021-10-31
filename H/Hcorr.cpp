//#include <iostream>
//
//
//using namespace std;
//
/////
///// @brief partitions given array into two parts: < pivot and >= pivot
///// pivot is chosen randomly
///// @return index between parts < pivot and >= pivot
/////
//int partition(int* mas, int l, int r) {
//    if (l != r) {
//        swap(mas[l + rand() % (r - l)], mas[r]);
//    }
//    int x = mas[r];
//    int i = l - 1;
//    for (int j = l; j <= r; j++) {
//        if (mas[j] <= x)
//            swap(mas[++i], mas[j]);
//    }
//    return i;
//}
//
/////
///// @brief using inequalities looks for kth element in array if is was sorted
/////
///// @return array[k] if it was sorted
/////
//int kth(int* mas, int k, int r) {
//    int l = 0;
//    while (true) {
//        int pos = partition(mas, l, r);
//        if (pos < k) {
//            l = pos + 1;
//        }
//        else if (pos > k) {
//            r = pos - 1;
//        }
//        else {
//            break;
//        }
//    }
//    return mas[k];
//}
//
//int main() {
//    int* mas = new int[10000001];
//    int n, k;
//    cin >> n >> k >> mas[0] >> mas[1];
//    for (int i = 2; i < n; ++i) {
//        mas[i] = ((mas[i - 1] * 123) + (mas[i - 2] * 45)) % 10004321;
//    }
//    cout << kth(mas, k, n);
//    delete[] mas;
//    return 0;
//}