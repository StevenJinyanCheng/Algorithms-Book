/**
 * calculate s = sin(n), c = cos(n)
**/
#include <stdio.h>
#include <math.h>

int main(int argc, const char *argv[]) {
    float f;
    scanf("%f", &f);
    float a = f * 3.14159265f / 180;  // Convert degrees to radians
    printf("%.3f %.3f", sin(a), cos(a));  // Use 'a' instead of 'f'
    return 0;
}
