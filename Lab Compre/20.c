#include <stdio.h>
#include <limits.h>

typedef long long ll;

ll minll(ll a, ll b) {
    return (a < b) ? a : b;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int A[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Check if it is possible to end with exactly 1 pile
    if ((n - 1) % (k - 1) != 0) {
        printf("-1\n");
        return 0;
    }

    // Prefix sums for quick range sum
    ll prefix[n + 1];
    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + A[i];
    }

    ll dp[n][n];

    // Initialize
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    // len = current interval length
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;

            // Try valid split points
            for (int m = i; m < j; m += (k - 1)) {
                dp[i][j] = minll(dp[i][j], dp[i][m] + dp[m + 1][j]);
            }

            // If this interval can be merged into exactly 1 pile,
            // add the sum of stones in this interval
            if ((j - i) % (k - 1) == 0) {
                dp[i][j] += prefix[j + 1] - prefix[i];
            }
        }
    }

    printf("%lld\n", dp[0][n - 1]);
    return 0;
}