#include <iostream>

/// 
/// @brief finds minimal quantity of operations to get to the number n
/// 
/// @param[in] n - watch brief
///
/// @note idea: doing min[0 ... 2] = -1 and choosing min >= 0
/// so if i in not divisible by 2 or(and) 3 we easily choose min[0]
/// min[0] - the shortest way to get i-1
/// min[1] - the shortest way to get i/2 if exists
/// min[2] - the shortest way to get i/3 if exists
/// 
/// @return minimal quantity of operations to get to the number n
///
int findMinWay(int n) {
    int* dp = new int[n + 1];
    // due to numeration starts from one for easy counting
    dp[0] = 0;
    dp[1] = 0;
    int min[3] = { 0 };

    for (int i = 2; i <= n; ++i) {

        for (int j = 0; j < 3; ++j) {
            min[j] = -1;
        }

        min[0] = dp[i - 1] + 1;
        if (!(i % 2)) { // if number is divisible by two
            min[1] = dp[i / 2] + 1;
        }
        if (!(i % 3)) {
            min[2] = dp[i / 3] + 1;
        }

        int minWay = static_cast<int>(1e7);
        // due to n <= 10e6, but just to be sure I did 1e7
        for (int j = 0; j < 3; ++j) {
            if (min[j] < minWay && min[j] >= 0) {
                minWay = min[j];
            }
        }

        dp[i] = minWay;
    }

    int minWayToN = dp[n];
    delete[] dp;
    return minWayToN;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << findMinWay(n);
    return 0;
}