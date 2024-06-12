#include<stdio.h>
int main(int argc, const char *argv[]){
    while(1){
        int n, m;
        scanf("%d%d", &n, &m);
        if(n == 0 && m == 0)break;
        if(n == 0 || m == 0){
            printf("Warning: n or m = 0\n");
            continue;
        }
        double res = 0;
        for(int i = n;i <= m;i++){
            res += 1.0 / i / i;
        }
        printf("%.5lf\n", res);
    }
    return 0;
}