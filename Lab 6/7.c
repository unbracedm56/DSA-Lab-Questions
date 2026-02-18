#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct StackInt{
    int arr[100];
    int top;
};

void initStackInt(struct StackInt *s){
    s->top = -1;
}

void pushInt(struct StackInt *s, int x){
    if(s->top >= 99){
        return;
    }
    s->top++;
    s->arr[s->top] = x;
}

int topInt(struct StackInt *s){
    if(s->top == -1){
        // return -1;
    }
    return s->arr[s->top];
}

void popInt(struct StackInt *s){
    if(s->top == -1){
        return;
    }
    s->top--;
}

int sizeInt(struct StackInt *s){
    return s->top + 1;
}

struct StackStr{
    char arr[100][100];
    int top;
};

void initStackStr(struct StackStr* s){
    s->top = -1;
}

void pushStr(struct StackStr* s, char x[]){
    if (s->top >= 99)
    {
        return;
    }
    s->top++;
    strcpy(s->arr[s->top], x);
}

void topStr(struct StackStr *s, char dest[]) {
    if(s->top == -1){
        return;
    }
    strcpy(dest, s->arr[(s->top)]);
}

void popStr(struct StackStr* s){
    if(s->top == -1){
        return;
    }
    s->top--;
}

int sizeStr(struct StackStr *s) {
    return s->top + 1;
}

int main(){
    int n;
    scanf("%d", &n);
    char str[100];
    scanf("%s", &str);

    struct StackInt stNum;
    struct StackStr stStr;
    initStackInt(&stNum);
    initStackStr(&stStr);

    char current[100] = "";
    int num = 0;

    for(int i = 0; i < strlen(str); i++){
        if(isdigit(str[i])){
            num = num * 10 + (str[i] - '0');
        }else if(str[i] == '['){
            pushInt(&stNum, num);
            pushStr(&stStr, current);

            num = 0;
            current[0] = '\0';
        }else if(str[i] == ']'){
            int a = topInt(&stNum);
            popInt(&stNum);
            char prev[100];
            topStr(&stStr, prev);
            popStr(&stStr);
            char temp[100] = "";
            
            for(int j = 0; j < a; j++){
                strcat(temp, current);
            }
            strcpy(current, prev);
            strcat(current, temp);
        }else{
            int l = strlen(current);
            current[l] = str[i];
            current[l + 1] = '\0';
        }
    }

    printf("%s", current);
    return 0;
}