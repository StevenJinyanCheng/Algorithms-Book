#include <stdio.h>
#include <stdbool.h>

int main() {
    int case_number = 1;
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;

        int a[11], b[11], c[11];
        int period[11], state[11];

        for(int i = 1; i <= n; i++){
            scanf("%d %d %d", &a[i], &b[i], &c[i]);
            period[i] = a[i] + b[i];
            state[i] = (c[i] - 1) % period[i] + 1;
        }

        bool found = false;
        for(int t = 1; t <= 10000; t++){ // Time
            int awake_count = 0;
            for(int i = 1; i <= n; i++){ // Count awake students
                if (state[i] <= a[i]) {
                    awake_count++;
                }
            }
            for(int i = 1; i <= n; i++){ // loop for state change
                if (state[i] < period[i]) {
                    state[i]++;
                } else {
                    state[i] = 1;
                }
                if (state[i] == a[i] + 1) {
                    if (awake_count >= (n - awake_count)) { // Change state
                        state[i] = 1;
                    }
                }
            }
            if (awake_count == n) { // Check
                printf("Case %d: %d\n", case_number, t);
                found = true;
                break;
            }
        }

        if (!found) {
            printf("Case %d: -1\n", case_number);
        }
        case_number++;
    }
    printf("\n");
    return 0;
}
