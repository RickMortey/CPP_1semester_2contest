/*#include <iostream>

///
/// @brief finds longest increasing subsequence (LIS)
///
/// @note idea: dp[i] - length of LIS for seq[0...i], at first dp[i] = 1
/// let's find it looking for such dp[j] from 0 to i-1
/// that dp[j] >= dp[i] and a[j] < a[i]
/// repeat i times (from 0 to i-1)
/// by that way we would find d[i]
/// Now we know length of LIS. Let's find LIS
/// allocate array prev[n] where in prev[i] we keep element
/// which stands before i-th element
///
/// @param[in] seq - sequence where we have to find LIS
///
/// @param[in] n - length of seq
///
/// @param[in] length - length of LIS
///
///
int* findLIS(int* seq, int n, int& length) {

    // creating helping arrays
    int* dp = new int[n];
    int* prev = new int[n];

    // filling dp & prev arrays
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; ++j) {
            if (seq[i] > seq[j] && dp[i] <= dp[j]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    // looking for length

    int position = 0;
    length = dp[position];
    for (int i = 0; i < n; ++i) {
        if (dp[i] > length) {
            position = i;
            length = dp[i];
        }
    }
    
    // looking for answer LIS

    int* answer = new int[length];
    int i = 0;
    while (position != -1) {
        answer[i] = seq[position];
        position = prev[position];
        ++i;
    }

    delete[] dp;
    delete[] prev;

    return answer;
}

int main() {
    int n;
    std::cin >> n;
    int* seq = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> seq[i];
    }
    int length = 0;
    int* answer = findLIS(seq, n, length);
    for (int i = length - 1; i >= 0; --i) {
        std::cout << answer[i] << ' ';
    }
}*/