#include <stdio.h>

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    
    int bays[m];
    for(int i = 0; i < m; i++){
        bays[i] = -1;
    }

    for(int i = 0; i < n; i++){
        int cont;
        scanf("%d", &cont);

        int idx = cont % m;

        while (1) {
            if (bays[idx] == -1) {
                bays[idx] = cont;
                break;
            }
            else if (cont >= 1000 && bays[idx] < 1000) {
                int temp = bays[idx];
                bays[idx] = cont;
                cont = temp;
            }

            idx = (idx + 1) % m;
        }
    }

    for(int i = 0; i < m; i++){
        printf("%d ", bays[i]);
    }
}