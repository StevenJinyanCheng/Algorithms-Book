#include<stdio.h>
int main(int argc, const char *argv[]){
    int n;
    scanf("%d", &n);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= i-1;j++){
            printf(" ");
        }
        for(int j = 1;j <= n * 2 + 1 - 2 * i;j++){
            printf("*");
        }
        for(int j = 1;j <= i-1;j++){
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}