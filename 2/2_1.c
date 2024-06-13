/** 
 *               ___      ___    3   3   3
 * calculate all ABC that ABC = A + B + C
**/
#include <stdio.h>
//#define CHEAT
int main(int argc, const char *argv[]){
#ifdef CHEAT
    printf("153 370 371 407\n");
    
#else
    for(int a = 1;a < 10;a++)
        for(int b = 0;b < 10;b++)
            for(int c = 0;c < 10;c++){
                if(a*100+b*10+c==a*a*a+b*b*b+c*c*c)printf("%d%d%d ", a, b, c);
            }
    printf("\n");
#endif
    return 0;
}