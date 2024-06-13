#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc, const char *argv[]){
    char a[1024];
    scanf("%s", a);
    float c = 12.01, h = 1.008, o = 16.00, n = 14.01;
    float curval = 0, total = 0;
    size_t s = strnlen(a, 1024);
    for(int i = 0; i < s; i++){
        if(isupper(a[i])){
            total += curval;
            curval = 0;
            switch(a[i]){
                case 'C': curval = c; break;
                case 'H': curval = h; break;
                case 'O': curval = o; break;
                case 'N': curval = n; break;
            }
        }
        if(a[i] >= '0' && a[i] <= '9'){
            int count = a[i] - '0';
            if(i > 0 && isdigit(a[i-1])){
                curval = curval / (a[i-1] - '0') * (10 * (a[i-1] - '0') + count);
            } else {
                curval *= count;
            }
        }
    }
    total += curval;
    printf("%.3f\n", total);
    return 0;
}
