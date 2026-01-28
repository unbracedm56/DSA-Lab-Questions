#include <stdio.h>
#include <limits.h>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

double medianFinding(int A[], int n, int B[], int m){
    double median = 0.0;
    if (n > m){
        return medianFinding(B, m, A, n);
    }
    int low = 0, high = n;

    while (low <= high)
    {
        int i = (low + high) / 2;

        int j = (n + m + 1) / 2 - i;

        int Aleft = (i > 0) ? A[i-1] : INT_MIN;
        int Aright = (i < n) ? A[i] : INT_MAX;
        int Bleft = (j > 0) ? B[j-1] : INT_MIN;
        int Bright = (j < m) ? B[j] : INT_MAX;

        if (Aleft <= Bright && Bleft <= Aright)
        {
            int total = n + m;
            if (total % 2 == 0){
                median = (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
                break;
            }else{
                median = (double)max(Aleft, Bleft);
                break;
            }
        }else if (Aleft > Bright){
            high = i - 1;
        }else{
            low = i + 1;
        }
    }
    return median;
}

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i<n; i++){
        scanf("%d", &A[i]);
    }
    int m;
    scanf("%d", &m);
    int B[m];
    for (int i = 0; i < m; i++){
        scanf("%d", &B[i]);
    }

    printf("%.2f", medianFinding(A, n, B, m));

    
}