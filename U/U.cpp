#include <iostream>

///
/// @brief finds number of Increasing Subsequences (IS) for mas[0...n-1]
///
/// @param[in] mas - array where we look for IS
///
/// @param[in] n - length of mas
///
/// @note: here we can see classic recurrent formula close to Fibonacci
/// in dp[i] we keep amount of LIS for mas[0...i]
/// for dp[i] is mas[i] > mas[j] => exists LIS
/// which contains some elements (or not) from mas[0...j]
/// and also contains mas[i]
/// therefore if mas[i] > mas[j] => 
/// dp[i] =( dp[i] % 1000000 + dp[j] % 1000000) % 1000000
int numberOfIncreasingSubsequences(int* mas, int n) {

    int* dp = new int[n];

    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (mas[j] < mas[i]) {
                dp[i] = (dp[i] % 1000000 + dp[j] % 1000000) % 1000000;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = (ans % 1000000 + dp[i] % 1000000) % 1000000;
    }

    delete[] mas;
    delete[] dp;

    return ans;
}

int main() {
    int n;
    std::cin >> n;
    int* mas = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> mas[i];
    }
    
    std::cout << numberOfIncreasingSubsequences(mas, n);

    return 0;
}

