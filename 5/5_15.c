#include "C:\ProgramData\anaconda3\Library\include\gmp.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#define MAX_FIB_SIZE 100000
#define MAX_FIB_DIGIT 20900

int main() {
    int T;
    scanf("%d", &T);

    char s[50];
    char *str = (char *)malloc(MAX_FIB_DIGIT);
    mpz_t now, last;
    mpz_init_set_ui(now, 0u);
    mpz_init_set_ui(last, 1u);

    while (T--) {
        int have = 0;
        memset(s, 0, sizeof(s));
        scanf("%40s", s);  // Ensure no buffer overflow
        size_t len = strnlen(s, sizeof(s));

        for (int i = 0; i <= MAX_FIB_SIZE; i++) {
            if (i > 1) {
                mpz_add(now, now, last);
                mpz_swap(now, last);
            } else if (i == 1) {
                mpz_set_ui(now, 1u);
            }

            gmp_sprintf(str, "%Zd", now);

            if (strncmp(str, s, len) == 0) {
                printf("%d\n", i-1); // magic
                have = 1;
                break;
            }
        }

        if (have == 0) printf("-1\n");

        mpz_set_ui(now, 0u);
        mpz_set_ui(last, 1u);
    }

    mpz_clear(now);
    mpz_clear(last);
    free(str);
    return 0;
}
