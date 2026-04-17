#include <stdio.h>

// Helper function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Recursive Divide & Conquer function
int solve(char* s, int left, int right, int k) {
    // 1. BASE CASE: If the remaining window is shorter than K, 
    // it's mathematically impossible to have a valid substring.
    if (right - left + 1 < k) {
        return 0;
    }

    int freq[26] = {0};

    // 2. Count the frequency of every character in the current window
    for (int i = left; i <= right; i++) {
        freq[s[i] - 'a']++;
    }

    // 3. Find the first "bad" character (frequency > 0 but < K)
    for (int i = left; i <= right; i++) {
        if (freq[s[i] - 'a'] > 0 && freq[s[i] - 'a'] < k) {
            
            // DIVIDE: We found a bad character at index 'i'. 
            // The valid string must be completely to its left OR completely to its right.
            int max_left = solve(s, left, i - 1, k);
            int max_right = solve(s, i + 1, right, k);
            
            // MERGE/CONQUER: Return whichever side gave us a longer valid substring
            return max(max_left, max_right);
        }
    }

    // 4. If the loop finishes without finding ANY bad characters, 
    // it means every character in this window appears at least K times!
    return right - left + 1;
}

int main() {
    int n, k;
    
    // Read N and K
    if (scanf("%d %d", &n, &k) != 2) return 0;

    // Allocate memory for the string (100005 to safely hold 10^5 characters + null terminator)
    char s[100005];
    if (scanf("%s", s) != 1) return 0;

    // Call the recursive function from index 0 to N-1
    int ans = solve(s, 0, n - 1, k);

    printf("%d\n", ans);

    return 0;
}