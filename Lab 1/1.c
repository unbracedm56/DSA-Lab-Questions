#include <stdio.h>

struct Student{
    int id;
    char name[20];
    float marks[3];
};

int main(){
    int n;
    scanf("%d", &n);

    struct Student arr[n];
    for(int i = 0; i<n; i++){
        scanf("%d %s %f %f %f", &arr[i].id, &arr[i].name, &arr[i].marks[0], &arr[i].marks[1], &arr[i].marks[2]);
    }

    int merit = 0;
    struct Student topper = arr[0];
    float topper_avg = (arr[0].marks[0] + arr[0].marks[1] + arr[0].marks[2]) / 3;
    printf("Merit List:\n");
    for(int i = 0; i<n; i++){
        float avg = (arr[i].marks[0] + arr[i].marks[1] + arr[i].marks[2])/3;

        if(avg > topper_avg){
            topper = arr[i];
            topper_avg = avg;
        }

        if(avg > 75){
            printf("%d %s (Avg: %.2f)\n", arr[i].id, arr[i].name, avg);
            merit++;
        }
    }
    if(merit == 0){
        printf("(No Output)\n");
    }
    printf("Topper: %s", topper.name);
}