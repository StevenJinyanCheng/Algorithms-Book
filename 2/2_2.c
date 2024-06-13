#include <stdio.h>
#include <stdbool.h>
int main(int argc, const char *argv[]){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    bool ok = false;
    for(int i = 10;i <= 100;i++){
        if((i % 3 == a) && (i % 5 == b) && (i % 7 == c)){
            printf("%d", i);
            ok = true;
        }
    }
    if(!ok)printf("No answer");
    return 0;
}