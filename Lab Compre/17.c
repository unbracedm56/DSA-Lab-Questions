#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

// Function to find maximum of three values
int max3(int a, int b, int c) {
    return MAX(a, MAX(b, c));
}

// Function to find maximum crossing sum
int maxCrossingSum(int A[], int l, int mid, int r) {
    int sum = 0;
    int leftSum = -1000000000;

    // Best suffix sum on left side
    for (int i = mid; i >= l; i--) {
        sum += A[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }

    sum = 0;
    int rightSum = -1000000000;

    // Best prefix sum on right side
    for (int i = mid + 1; i <= r; i++) {
        sum += A[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }

    return leftSum + rightSum;
}

// Divide and conquer function
int maxSubarraySum(int A[], int l, int r) {
    // Base case: only one element
    if (l == r) {
        return A[l];
    }

    int mid = (l + r) / 2;

    // Solve left half
    int leftAns = maxSubarraySum(A, l, mid);

    // Solve right half
    int rightAns = maxSubarraySum(A, mid + 1, r);

    // Solve crossing case
    int crossAns = maxCrossingSum(A, l, mid, r);

    // Return best of all three
    return max3(leftAns, rightAns, crossAns);
}

int main() {
    int n;
    scanf("%d", &n);

    int A[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int ans = maxSubarraySum(A, 0, n - 1);
    printf("%d\n", ans);

    return 0;
}