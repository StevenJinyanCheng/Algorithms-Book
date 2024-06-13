#include<stdio.h>
#include <string.h>

int main(int argc, const char *argv[]){
    char a[100];
    scanf("%s", a);
    size_t s = strnlen(a, 80);
    for(int i = 1;i <= s;i++){
        if(s % i == 0){
            char obuf[100];
            int flag = 1;
            strncpy(obuf, a, i);
            for(int j = 0; j < s;j += i){
                char buf[100];
                strncpy(buf, a + j, i);
                if(strncmp(obuf, buf, 80)){
                    flag = 0;
                }
            }
            if(flag){printf("%d", i);return 0;}
        }
    }
    return 0;
}