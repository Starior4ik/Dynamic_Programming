#include <iostream>

int main() {
    int arr[8] = {5, 4, 1, 2, 5, 3, 6, 7};
    int len[8];
    int pos[8];
    int prev[8];
    int length = 0;

    pos[0] = -1;
    len[0] = -1;
    for (int i = 1; i < 8; i++) {
        len[i] = INF;
    }
       
    for (int i = 1; i < 7; i++) {
       int j = binary_search(len, arr[i]);
        if (len[j - 1] < arr[i] and arr[i] < len[j]) {
           len[j] = arr[i];
           pos[j] = i;
           prev[i] = pos[j - 1];
           length = std::max(length, j);
        }
    }

    int p = pos[length];
    int i = length - 1;
    int answer[8];
    while (p != -1) {
        answer[i] = arr[p];
        p = prev[p];
        i--;
    }
}
