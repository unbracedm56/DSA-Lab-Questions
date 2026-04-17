#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long ll;

typedef struct {
    ll x, y;
    int type;   // 1 -> point belongs to P1, 2 -> point belongs to P2
} Point;

// Return minimum of two long long values
ll minll(ll a, ll b) {
    return (a < b) ? a : b;
}

// Absolute value for long long
ll absll(ll x) {
    return (x < 0) ? -x : x;
}

// Manhattan distance between two points
ll manhattan(Point a, Point b) {
    return absll(a.x - b.x) + absll(a.y - b.y);
}

// Sort points by x, then by y
int cmpX(const void *a, const void *b) {
    Point *p = (Point *)a;
    Point *q = (Point *)b;

    if (p->x < q->x) return -1;
    if (p->x > q->x) return 1;
    if (p->y < q->y) return -1;
    if (p->y > q->y) return 1;
    return 0;
}

// Sort points by y, then by x
int cmpY(const void *a, const void *b) {
    Point *p = (Point *)a;
    Point *q = (Point *)b;

    if (p->y < q->y) return -1;
    if (p->y > q->y) return 1;
    if (p->x < q->x) return -1;
    if (p->x > q->x) return 1;
    return 0;
}

// Divide and conquer function
// Finds minimum Manhattan distance between one point from P1
// and one point from P2 in pts[l...r]
ll solve(Point pts[], int l, int r) {
    // Base case: very small segment -> brute force
    if (r - l <= 3) {
        ll ans = LLONG_MAX;

        for (int i = l; i <= r; i++) {
            for (int j = i + 1; j <= r; j++) {
                // Only compare points from different sets
                if (pts[i].type != pts[j].type) {
                    ll d = manhattan(pts[i], pts[j]);
                    if (d < ans) {
                        ans = d;
                    }
                }
            }
        }

        return ans;
    }

    // Divide into two halves
    int mid = (l + r) / 2;
    ll midX = pts[mid].x;

    // Solve left half and right half
    ll leftAns = solve(pts, l, mid);
    ll rightAns = solve(pts, mid + 1, r);

    // Best answer found so far
    ll d = minll(leftAns, rightAns);

    // Build strip: points close enough to the middle line
    Point strip[r - l + 1];
    int sz = 0;

    for (int i = l; i <= r; i++) {
        if (absll(pts[i].x - midX) < d) {
            strip[sz] = pts[i];
            sz++;
        }
    }

    // Sort strip by y-coordinate
    qsort(strip, sz, sizeof(Point), cmpY);

    // Check candidate cross pairs in the strip
    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
            // If y difference itself is already >= d, no need to continue
            if (strip[j].y - strip[i].y >= d) {
                break;
            }

            // Only compare points from different sets
            if (strip[i].type != strip[j].type) {
                ll cur = manhattan(strip[i], strip[j]);
                if (cur < d) {
                    d = cur;
                }
            }
        }
    }

    return d;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int total = N + M;
    Point pts[total];

    // Read points of P1
    for (int i = 0; i < N; i++) {
        scanf("%lld %lld", &pts[i].x, &pts[i].y);
        pts[i].type = 1;
    }

    // Read points of P2
    for (int i = 0; i < M; i++) {
        scanf("%lld %lld", &pts[N + i].x, &pts[N + i].y);
        pts[N + i].type = 2;
    }

    // Sort all points by x-coordinate
    qsort(pts, total, sizeof(Point), cmpX);

    // Solve on the full range
    ll ans = solve(pts, 0, total - 1);

    printf("%lld\n", ans);
    return 0;
}