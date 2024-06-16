#include <stdio.h>
#include <stdbool.h>

bool Hs[15][15];
bool Vs[15][15];

int main(int argc, const char *argv[]) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        char p;
        int a, b;
        scanf(" %c %d %d", &p, &a, &b);
        if (p == 'H') {
            Hs[a][b] = true;
        }
        if (p == 'V') {
            Vs[a][b] = true;
        }
    }

    bool foundAnySquares = false;
    for (int size = 1; size <= n; size++) {
        int count = 0;
        for (int i = 1; i <= n - size; i++) {
            for (int j = 1; j <= n - size; j++) {
                bool flag = true;
                for (int k = 0; k < size; k++) {
                    if (!Hs[i][j + k] || !Hs[i + size][j + k] || !Vs[i + k][j] || !Vs[i + k][j + size]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    count++;
                }
            }
        }
        if (count > 0) {
            printf("%d square(s) with size %d\n", count, size);
            foundAnySquares = true;
        }
    }

    if (!foundAnySquares) {
        printf("No completed squares can be found.\n");
    }

    return 0;
}
