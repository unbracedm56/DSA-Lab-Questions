#include <stdio.h>
#include <string.h>

int main(){
    char str[200];
    fgets(str, sizeof(str), stdin);

    int count = 0, in_word = 0;
    int vowel_count = 0;
    for(int i = 0; i<strlen(str); i++){
        if(str[i] == ' '){
            in_word = 0;
        }else if(!in_word){
            in_word = 1;
            count++;
        }
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            vowel_count++;
        }
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
            vowel_count++;
        }
    }

    printf("Words: %d\n", count);
    printf("Vowels: %d\n", vowel_count);
    printf("Reversed: ");
    for(int i = strlen(str) - 1; i>=0; i--){
        printf("%c", str[i]);
    }
}