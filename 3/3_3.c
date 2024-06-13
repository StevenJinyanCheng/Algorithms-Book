#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[]){
    char a[50000] = {};
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++){
        char s[6];
        snprintf(s, 6, "%d", i);
        strncat(a, s, 50000 - strlen(a) - 1);
    }
    
    int cnt[10] = {0};
    
    for(int i = 0; i < strnlen(a, 50000); i++) cnt[a[i] - '0']++;
    
    for(int i = 0; i < 10; i++) printf("%d ", cnt[i]);
    
    return 0;
}
