#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main(){
    int n;
    scanf("%d", &n);

    int energy_output[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &energy_output[i]);
    }

    if(n == 1){
        printf("%d", energy_output[0]);
        return 0;
    }

    if(n == 2){
        printf("%d", MAX(energy_output[0], energy_output[1]));
        return 0;
    }

    int dp_first[n - 1];
    dp_first[0] = energy_output[0];
    dp_first[1] = MAX(energy_output[0], energy_output[1]);
    int dp_last[n - 1];
    dp_last[0] = energy_output[1];
    dp_last[1] = MAX(energy_output[1], energy_output[2]);

    for(int i = 2; i < n - 1; i++){
        dp_first[i] = MAX(dp_first[i - 1], dp_first[i - 2] + energy_output[i]);
    }
    for(int i = 2; i < n - 1; i++){
        dp_last[i] = MAX(dp_last[i - 1], dp_last[i - 2] + energy_output[i + 1]);
    }

    printf("%d", MAX(dp_first[n - 2], dp_last[n - 2]));
}