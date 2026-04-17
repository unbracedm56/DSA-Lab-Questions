#include <stdio.h>

typedef long long ll;

// Merge two sorted halves A[l..mid] and A[mid+1..r]
void merge(int A[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int left[n1], right[n2];

    for (int i = 0; i < n1; i++) {
        left[i] = A[l + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = A[mid + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            A[k++] = left[i++];
        } else {
            A[k++] = right[j++];
        }
    }

    while (i < n1) {
        A[k++] = left[i++];
    }

    while (j < n2) {
        A[k++] = right[j++];
    }
}

// Modified merge sort that counts important reverse pairs
ll mergeSortCount(int A[], int l, int r, int K) {
    if (l >= r) {
        return 0;
    }

    int mid = (l + r) / 2;

    ll count = 0;

    // Count in left half and right half
    count += mergeSortCount(A, l, mid, K);
    count += mergeSortCount(A, mid + 1, r, K);

    // Count cross pairs
    int j = mid + 1;
    for (int i = l; i <= mid; i++) {
        while (j <= r && (ll)A[i] > (ll)K * A[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }

    // Merge the two sorted halves
    merge(A, l, mid, r);

    return count;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    ll ans = mergeSortCount(A, 0, N - 1, K);

    printf("%lld\n", ans);

    return 0;
}