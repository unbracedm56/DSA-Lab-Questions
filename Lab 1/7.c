#include <stdio.h>
#include <string.h>

int main(){
    char str[200];
    scanf("%s", &str);
    char final[200];

    int a = 0, count = 0;
    char curr = str[0];
    for(int i = 0; i<strlen(str); i++){
        if(curr == str[i]){
            count++;
        }else {
            final[a++] = curr;
            a += sprintf(&final[a], "%d", count);
            curr = str[i];
            count = 1;
        }
    }
    final[a++] = curr;
    a += sprintf(&final[a], "%d", count);
    final[a] = '\0';

    if(strlen(final) <= strlen(str)){
        printf("%s", final);
    }else{
        printf("%s", str);
    }
    
}
