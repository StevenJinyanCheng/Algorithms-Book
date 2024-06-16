#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[]){
    int k;
    scanf("%d", &k);
    for(int _i = 1; _i <= k; _i++){
        char a[50000] = {0};
        int n;
        scanf("%d", &n);
        
        for(int i = 1; i <= n; i++){
            char s[6];
            snprintf(s, sizeof(s), "%d", i);
            strncat(a, s, sizeof(a) - strlen(a) - 1);
        }
        
        int cnt[10] = {0};
        
        for(int i = 0; i < strnlen(a, sizeof(a)); i++) cnt[a[i] - '0']++;
        
        for(int i = 0; i < 10; i++) printf("%d ", cnt[i]);
        printf("\n");
    }  
    return 0;
}
