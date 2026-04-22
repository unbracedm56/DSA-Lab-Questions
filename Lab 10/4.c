#include <stdio.h>

int main() {
    int M, R;
    scanf("%d %d", &M, &R);

    int N;
    scanf("%d", &N);

    int table[M];
    for (int i = 0; i < M; i++) {
        table[i] = -1;
    }

    for (int i = 0; i < N; i++) {
        int k;
        scanf("%d", &k);

        int h1 = k % M;
        int h2 = R - (k % R);

        int j = 0;

        while (1) {
            int idx = (h1 + j * h2) % M;

            if (table[idx] == -1) {
                table[idx] = k;
                break;
            }

            j++;
        }
    }

    for (int i = 0; i < M; i++) {
        printf("%d", table[i]);
        if (i < M - 1) printf(" ");
    }

    return 0;
}