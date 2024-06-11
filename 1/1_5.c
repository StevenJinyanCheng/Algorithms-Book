/** 
 * calculate y = ((95 * x) >= 300)?(95 * 0.85 * x):(95 * x)
**/
#include <stdio.h>

int main() {
    float x, y;
    scanf("%f", &x);
    y = ((95 * x) >= 300) ? (95 * 0.85 * x) : (95 * x);
    printf("%.2f\n", y);
    
    return 0;
}
