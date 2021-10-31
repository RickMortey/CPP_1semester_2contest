#include <iostream>

int lengthLIS(int*a, int n) {
    int* dp = new int[n + 1];
    dp[0] = -100001;
    for (int i = 1; i <= n; ++i) {
        dp[i] = 100001;
    }

    // dp - array where we keep element on which LIS ends
    // obviously, d[i-1] <= d[i] => we can use binSearch
    // to find in d 1st num which is bigger than a[i] and update it
    // so until dp[i] != 100001 LIS exists
    // let's make counter according to latest statement
    for (int i = 0; i < n; ++i) {

        int left = 0;
        int right = i + 1;

        while (left <= right) {
            int mid = (left + right + 1) / 2;

            if (a[i] > dp[mid]) {
                left = mid;
                if (a[i] <= dp[mid + 1]) {
                    right = mid + 1;
                    break;
                }
            }
            else {
                right = mid;
                if (a[i] > dp[mid - 1]) {
                    right = mid;
                    break;
                }
            }

        }


        if (dp[right - 1] < a[i] && a[i] < dp[right]) {
            dp[right] = a[i];
        }

    }


    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        if (dp[i] != 100001) {
            answer++;
        }
    }

    delete[] a;
    delete[] dp;
    return answer;
}
int main() {

    int n;
    std::cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        std::cout << lengthLIS(&a[i], n - i) << ' ';
    }
    return 0;
}

