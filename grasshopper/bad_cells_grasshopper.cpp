#include <iostream>

const int N = 20;
int main() {
    int BAD_CELLS[] = {2, 3, 6, 13};

    int dp[N+1] {0};
    int is_bad[N+1] {0};
    for (int bad : BAD_CELLS) {
        is_bad[bad] = 1;
    }

    if (is_bad[1] != 1) {
        dp[1] = 1;
    } 

    for (int i = 2; i < N + 1; i++){
        if (is_bad[i] != 1) {
            for (int k = 1; k < 4; k++) {
                if (i - k >= 1) {
                    dp[i] += dp[i - k];
                }
            }
        }
    }

    std::cout << dp[20];    
}