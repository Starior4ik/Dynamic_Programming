#include <iostream>

const int N = 20;

int main() {
    int dp[N+1] {0};
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i < N + 1; i++) {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }
    std::cout << dp[20];
}