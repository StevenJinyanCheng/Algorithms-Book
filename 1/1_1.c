/** 
 * Average of 3 numbers
 **/
#include<stdio.h>
int main(int argc, const char *argv[]){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("\n%.3f\n", 1.f / 3 * (a+b+c));
    return 0;
}