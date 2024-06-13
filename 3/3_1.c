#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[]){
    char a[100];
    scanf("%s", a);
    size_t s = strnlen(a, 80);
    int l = 0, cnt = 0;
    for(int i = 0;i < s;i++){
        if(a[i] == 'X'){
            l = 0;
        }
        else{
            l++;
        }
        cnt += l;
    }
    printf("%d", cnt);
    return 0;
}