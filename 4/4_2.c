#include <stdio.h>
int Hs[400][2];
int Vs[400][2];
int main(int argc, const char *argv[]){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= m;i++){
        char p;
        int a, b;
        scanf("%c %d %d", &p, &a, &b);
        if(p == 'H'){
            Hs[i][0] = a;
            Hs[i][1] = b;
        }
        if(p == 'V'){
            Vs[i][0] = a;
            Vs[i][1] = b;
        }
    }
    
    return 0;
}