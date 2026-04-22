#include <stdio.h>

int main(){
    int m, q;
    scanf("%d %d", &m, &q);

    int table[m];
    for(int i = 0; i < m; i++){
        table[i] = -1;
    }

    for(int i = 0; i < q; i++){
        int x, k;
        scanf("%d %d", &x, &k);

        if(x == 1){
            int idx = k % m;
            while(1){
                if(table[idx] == -1 || table[idx] == -2){
                    table[idx] = k;
                    break;
                }

                idx = (idx + 1) % m;
            }
        }else if(x == 2){
            int idx = k % m;
            int start = idx;
            while(1){
                if(table[idx] == k){
                    table[idx] = -2;
                    break;
                }

                idx = (idx + 1) % m;
                if(idx == start) break;
            }
        }else if(x == 3){
            int idx = k % m;
            int start = idx;
            while(1){
                if(table[idx] == k){
                    printf("Found\n");
                    break;
                }

                idx = (idx + 1) % m;
                if(idx == start){ 
                    printf("Not Found\n");
                    break;
                }
            }
        }
    }

    for(int i = 0; i < m; i++){
        printf("%d ", table[i]);
    }
}