#include <iostream>
#include <string.h>

///
/// @brief finds minimum of three elements
///
/// @param[in] a, b,c - input numbers, among them you need to find the minimum
///
/// @return minimum amoung a, b, c
///
int minOfThree(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}
///
/// @brief finds Levenstein distance for strFirst and strSecond
///
/// @ note idea: dynamic programming helps to fill dp matrix
/// in dp[i][j] we keep Levenstein distance
/// for strFirst[0...i], strSecond[0...j] => prefix dynamic programming
///
/// @param[in] dp - array where we keep intermediate results
///
/// @param[in] rows - height of dp
///
/// @param[in] cols - width of dp
///
/// @param[in] strFirst - one of two string for whose we fond Levenstein dist
///
/// @param[in] strSecond - same as strFirst
///
/// @return Levenstein distance for strFirst and strSecond
///
int Levenstein(int** dp, int rows, int cols, char* strFirst, char* strSecond) {

    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            if (strFirst[i - 1] != strSecond[j - 1]) {
                int deleteSymbol = dp[i - 1][j] + 1;
                int addSymbol = dp[i][j - 1] + 1;
                int changeSymbol = dp[i - 1][j - 1] + 1;
                dp[i][j] = minOfThree(deleteSymbol, addSymbol, changeSymbol);
            }
            else {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    return dp[rows][cols];
}

int main() {

    char* strFirst, * strSecond;
    strFirst = new char[1001];
    strSecond = new char[1001];
    std::cin >> strFirst >> strSecond;
    int rows = strlen(strFirst);
    int cols = strlen(strSecond);

    int** dp = new int* [rows + 1];
    for (int i = 0; i <= rows; ++i) {
        dp[i] = new int[cols + 1];
    }
    for (int i = 0; i <= rows; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= cols; ++j) {
        dp[0][j] = j;
    }

    std::cout << Levenstein(dp, rows, cols, strFirst, strSecond);

    delete[] strFirst;
    delete[] strSecond;
    for (int i = 0; i <= rows; ++i) {
        delete[] dp[i];
    }
    delete[] dp;

    return 0;
}