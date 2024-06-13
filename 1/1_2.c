/** 
 * calculate c = 5(f-32)/9
**/
#include <stdio.h>
int main(int argc, const char *argv[]){
    float f;
    scanf("%f", &f);
    printf("%.3f", 5.f*(f-32)/9);
    return 0;
}