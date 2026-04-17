#include <stdio.h>

typedef long long ll;

typedef struct {
    ll sum0, pref0, suff0, best0;
    ll sum1, pref1, suff1, best1;
} Node;

ll max2(ll a, ll b) {
    return (a > b) ? a : b;
}

ll max3(ll a, ll b, ll c) {
    return max2(a, max2(b, c));
}

ll max4(ll a, ll b, ll c, ll d) {
    return max2(max2(a, b), max2(c, d));
}

Node merge(Node L, Node R) {
    Node res;

    // total sum
    res.sum0 = L.sum0 + R.sum0;
    res.sum1 = max2(L.sum1 + R.sum0, L.sum0 + R.sum1);

    // best prefix
    res.pref0 = max2(L.pref0, L.sum0 + R.pref0);
    res.pref1 = max3(L.pref1,
                     L.sum1 + R.pref0,
                     L.sum0 + R.pref1);

    // best suffix
    res.suff0 = max2(R.suff0, R.sum0 + L.suff0);
    res.suff1 = max3(R.suff1,
                     R.sum1 + L.suff0,
                     R.sum0 + L.suff1);

    // best subarray
    res.best0 = max3(L.best0,
                     R.best0,
                     L.suff0 + R.pref0);

    res.best1 = max4(L.best1,
                     R.best1,
                     L.suff1 + R.pref0,
                     L.suff0 + R.pref1);

    return res;
}

Node solve(int A[], int l, int r) {
    if (l == r) {
        Node res;
        ll x = A[l];
        ll sq = x * x;

        res.sum0 = res.pref0 = res.suff0 = res.best0 = x;
        res.sum1 = res.pref1 = res.suff1 = res.best1 = sq;

        return res;
    }

    int mid = (l + r) / 2;
    Node left = solve(A, l, mid);
    Node right = solve(A, mid + 1, r);

    return merge(left, right);
}

int main() {
    int n;
    scanf("%d", &n);

    int A[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    Node ans = solve(A, 0, n - 1);
    printf("%lld\n", ans.best1);

    return 0;
}