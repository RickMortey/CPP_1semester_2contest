#include <iostream>

using namespace std;

///
/// @brief finds max of two numbers
///
/// @param[in] a, b - numbers where max must be found
///
/// @return max of two numbers
///
int max(int a, int b) {
    int res;
    if (a >= b) {
        res = a;
    }
    else {
        res = b;
    }
    return res;
}

///
/// @brief output each item we have taken into backpack
///
/// @param[in] dp - in dp[i][j] we keep max price is if there were only
/// items with indices from 1 to i and if lifting capacity is j
/// 
/// @param[in] n, m - size of dp
///
/// @param[in] w - weights of items
///
/// @param[in] p - prices of items
///
/// @note idea: we maximize price in each dp[i][j] without greedy algorithm
/// we compare dp[i-1][j] and price + dp[i - 1][j - weight]
/// is first is bigger than second, item is not taken
/// or total profit with it in backpack is less than without it
/// otherwise it is taken
void backpack(int** dp, int* w, int* p, int n, int m) {
    for (int j = 0; j < m + 1; ++j) {
        dp[0][j] = 0;
    }
    for (int i = 0; i < n + 1; ++i) {
        dp[i][0] = 0;
    }
    // filling up and left with zeros to be able to use them in calculating
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            int weight;
            int price;
            if (w[i - 1] <= j) {
                weight = w[i - 1];
                price = p[i - 1];
            }
            else {
                weight = 0;
                price = 0;
            } 
            dp[i][j] = max(dp[i - 1][j], (price + dp[i - 1][j - weight]));
        }
    }
}

///
/// @brief output each item we have taken into backpack
///
/// @param[in] dp - in dp[i][j] we keep max price is if there were only
/// items with indices from 1 to i and if lifting capacity is j
/// 
/// @param[in] n, m - size of dp
///
/// @param[in] w - weights of items
///
/// @param[in] p - prices of items
///
void digOutput(int**& dp, int n, int m, int* w, int* p) {
    int currw = m;
    int num = n;
    while (num >= 1) {
        if (currw - w[num - 1] >= 0) {
            if (dp[num][currw] - dp[num - 1][currw - w[num - 1]] == p[num - 1])
            {
                cout << num << "\n";
                currw -= w[num - 1]; // numeration starts from zero
            }
        }
        --num;
    }

}

int main() {
    int n, m;
    cin >> n >> m;
    int* w = new int[n];
    int* p = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    int** dp = new int* [n + 1];
    for (int i = 0; i < n + 1; ++i) {
        dp[i] = new int[m + 1];
    }

    backpack(dp, w, p, n, m);
    digOutput(dp, n, m, w, p);


    delete[] w;
    delete[] p;
    for (int i = 0; i <= n; ++i) {
        delete[] dp[i];
    }
    delete[] dp;
}