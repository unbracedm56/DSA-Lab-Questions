#include <stdio.h>

typedef long long ll;

// Merge sort based function to count valid range sums
ll mergeSortCount(ll prefix[], int l, int r, ll lower, ll upper) {
    if (l >= r) {
        return 0;
    }

    int mid = (l + r) / 2;

    // Count in left half and right half
    ll count = 0;
    count += mergeSortCount(prefix, l, mid, lower, upper);
    count += mergeSortCount(prefix, mid + 1, r, lower, upper);

    // Count cross pairs
    int p = mid + 1;
    int q = mid + 1;

    for (int i = l; i <= mid; i++) {
        while (p <= r && prefix[p] - prefix[i] < lower) {
            p++;
        }
        while (q <= r && prefix[q] - prefix[i] <= upper) {
            q++;
        }
        count += (q - p);
    }

    // Merge the two sorted halves
    ll temp[r - l + 1];
    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r) {
        if (prefix[i] <= prefix[j]) {
            temp[k++] = prefix[i++];
        } else {
            temp[k++] = prefix[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = prefix[i++];
    }

    while (j <= r) {
        temp[k++] = prefix[j++];
    }

    for (int t = 0; t < k; t++) {
        prefix[l + t] = temp[t];
    }

    return count;
}

int main() {
    int N;
    ll lower, upper;
    scanf("%d %lld %lld", &N, &lower, &upper);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Build prefix sums
    ll prefix[N + 1];
    prefix[0] = 0;

    for (int i = 0; i < N; i++) {
        prefix[i + 1] = prefix[i] + A[i];
    }

    ll ans = mergeSortCount(prefix, 0, N, lower, upper);

    printf("%lld\n", ans);
    return 0;
}