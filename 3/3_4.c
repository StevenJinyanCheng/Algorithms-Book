#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[]){
    int k;
    scanf("%d", &k);
    for(int _i = 1; _i <= k; _i++){
        char a[100] = {0};
        scanf("%s", a);
        size_t s = strnlen(a, 80);
        for(int i = 1; i <= s; i++){
            if(s % i == 0){
                char obuf[100] = {0};
                int flag = 1;
                strncpy(obuf, a, i);
                obuf[i] = '\0';
                
                for(int j = i; j < s; j += i){
                    if(strncmp(obuf, a + j, i) != 0){
                        flag = 0;
                    }
                }
                if(flag){
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }
    return 0;
}
