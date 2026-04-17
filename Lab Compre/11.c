#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long arr[10000];
    int size;
} Result;

long long apply(long long a, long long b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    return a * b;
}

Result solve(char s[], int l, int r) {
    Result res;
    res.size = 0;

    if (l == r) {
        res.arr[0] = s[l] - '0';
        res.size = 1;
        return res;
    }

    for (int i = l + 1; i < r; i += 2) {
        char op = s[i];

        Result left = solve(s, l, i - 1);
        Result right = solve(s, i + 1, r);

        for (int a = 0; a < left.size; a++) {
            for (int b = 0; b < right.size; b++) {
                if(s[i] == '+'){
                    res.arr[res.size] = left.arr[a] + right.arr[b];
                }else if(s[i] == '-'){
                    res.arr[res.size] = left.arr[a] - right.arr[b];
                }else{
                    res.arr[res.size] = left.arr[a] * right.arr[b];
                }
                res.size++;
            }
        }
    }

    return res;
}

void bubbleSort(long long arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                long long temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);

    char s[25];
    scanf("%s", s);

    Result ans = solve(s, 0, n - 1);

    bubbleSort(ans.arr, ans.size);

    for (int i = 0; i < ans.size; i++) {
        printf("%lld", ans.arr[i]);
        if (i + 1 < ans.size) printf(" ");
    }
}