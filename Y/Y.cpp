#include <iostream>
#include <string.h>

///
/// @brief finds max of two numbers
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
/// @brief recurrently looks for length 
/// of the longest panilndromic subsequence (further LPS) in string a[i...j]
///
/// @param[in] a - string where we look for
///
/// @param[in] dp - array where we keep some(not all)
/// results for LPS for a[i, j]
///
/// @param[in] - left boundary of string where we look for LPS
///
/// @param[in] - right boundary of string where we look for LPS
///
/// @return LPS for a[i...j]
///
int ijLen(char* a, int** dp, int i, int j) {
    if (dp[i][j] == -1) {
        if (a[i] == a[j]) {
            dp[i][j] = ijLen(a, dp, i + 1, j - 1) + 2;
        }
        else {
            dp[i][j] = max(ijLen(a, dp, i + 1, j), ijLen(a, dp, i, j - 1));
        }
    }
    return dp[i][j];
}

///
/// @brief looks for LPS in string a
///
/// @ note fucntion does pre-calculation of array dp,
/// then ijLen func is called for i = 0, j = length - 1.
/// So, this is the answer
/// 
/// @param[in] a - string where we look for
///
/// @param[in] length - length of string a
///
int lengthOfLongestPanildmoricSubsequence(char* a, int length) {

    // array allocation
    int** dp = new int* [length];
    for (int i = 0; i < length; ++i) {
        dp[i] = new int[length];
    }

    // pre-calculation
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            if (i == j) {
                dp[i][j] = 1;
            }
            else if (i > j) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = -1;
            }
        }
    }

    int answer = ijLen(a, dp, 0, length - 1);

    for (int i = 0; i < length; ++i) {
        delete[] dp[i];
    }
    delete[] dp;
    
    return answer;
}
///
/// @brief idea: obviously, we delete minimum amount of letters
/// if palindromic subsequence is longest
/// therefore answer = length - lengthOfLPS
///
int main() {
    const int maxLengthOfString = 10001;
    char* a = new char[maxLengthOfString];
    std::cin >> a;

    int length = strlen(a);
    int lengthOfLPS = lengthOfLongestPanildmoricSubsequence(a, length);
    int leastAmountOfLettersMustBeDeleted = length - lengthOfLPS;

    std::cout << leastAmountOfLettersMustBeDeleted;

    delete[] a;

    return 0;
}