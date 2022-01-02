#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int f[N], g[N];

// f[i] is number of way to fill the rectangle
// g[i] is number of way to fill the rectangle without upperleft or lowerleft ceil.

int main() {
    freopen("Problem5.inp", "r", stdin);
   freopen("Problem5.out", "w", stdout);

    f[0] = f[1] = 1; g[0] = 1;
    for (int i = 2; i < N; ++i) {
        f[i] = (f[i - 1] + f[i - 2] + 2 * g[i - 1]) % 10000;
        g[i] = (g[i - 1] + f[i - 2]) % 10000;
    }
    int test; scanf("%d", &test);
    while (test--) {
        int n; scanf("%d", &n);
        printf("%d\n", f[n]);
    }


    return 0;
}
