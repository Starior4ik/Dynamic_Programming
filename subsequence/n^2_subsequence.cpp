#include <iostream>

int main() {
    int arr[8] = {5, 4, 1, 2, 5, 3, 6, 7};
    int len[8];
    int prev[8];

    for (int i = 0; i < 8; i++) {
        len[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; j++) {  
            if (arr[j] < arr[i] && len[j] + 1 > len[i]) {
                len[i] = len[j] + 1;
                prev[i] = j;
            }
        }
    }

    int pos = 0;
    int max_len = len[0];
    for (int i = 0; i < 8; i++) {
        if (len[i] > max_len) {
            pos = i;
            max_len = len[i];
        }
    }
    std::cout << max_len << std::endl;  

    int answer[5];
    int last_ind = 4;
    while (pos != -1) {
        answer[last_ind] = arr[pos];
        pos = prev[pos];
        last_ind--;
    }

    for (int i = 0; i < 5; i++) {
        std::cout << answer[i] << " ";
    }
}
