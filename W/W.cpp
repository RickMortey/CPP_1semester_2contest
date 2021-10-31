#include <iostream>


///
/// @brief finds max of two numbers
///
/// @param[in] a, b - numbers where max must be found
///
/// @return max of two numbers
///
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}


///
/// @brief finds longest common subsequnce (LCS) for arrays x and y
/// 
/// @param[in] x, y - arrays where we have to find LCS
///
/// @param[in] n, m - lengths of arrays x and y respectively
///
/// @param[in] lengthOfLCS is length of LCS we would need to build LCS
///
/// @note idea: let's build dp where we keep in dp[i][j] LCS(x[0...i], y[0...j]
/// if x[i] == y[j] it is contained in dp[i][j] = LCS(x[i-1], y[j - 1]) + 1
/// else the element is either contained in dp[i-1][j] or dp[i][j-1]
/// as we are looking for longest common subsequence, dp[i][j] = max(...) + 1
///
int* findLCS(int* x, int n, int* y, int m, int& lengthOfLCS) {

    // n - length of x, m - length of y
    int** dp = new int* [n + 1];
    for (int i = 0; i < n + 1; ++i) {
        dp[i] = new int[m + 1];
    }

    // filling edge sides with zeros
    for (int i = 0; i < m + 1; ++i) {
        dp[0][i] = 0;
    }
    for (int i = 1; i < n + 1; ++i) {
        dp[i][0] = 0;
    }
    // filling dp
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            if (x[i - 1] == y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    lengthOfLCS = dp[n][m];
    int* LCS = new int[lengthOfLCS];
    int index = lengthOfLCS - 1;
    int i = n;
    int j = m;
    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            LCS[index] = x[i - 1];
            --i;
            --j;
            --index;
        }
        else if (dp[i - 1][j] == dp[i][j]) {
            --i;
        }
        else {
            --j;
        }
    }

    return LCS;
}

int main() {

    int n, m;

    std::cin >> n;
    int* x = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }

    std::cin >> m;
    int* y = new int[m];
    for (int i = 0; i < m; ++i) {
        std::cin >> y[i];
    }

    int lengthOfLCS;
    int* LCS = findLCS(x, n, y, m, lengthOfLCS);

    for (int i = 0; i < lengthOfLCS; ++i) {
        std::cout << LCS[i] << ' ';
    }
}