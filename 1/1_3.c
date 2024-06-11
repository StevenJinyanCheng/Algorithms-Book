/** 
 * calculate v = n*(n+1)/2
**/
#include<stdio.h>
int main(int argc, const char *argv[]){
    int n;
    scanf("%d", &n);
    printf("%lld", (long long)n*(n+1)/2);
    return 0;
}