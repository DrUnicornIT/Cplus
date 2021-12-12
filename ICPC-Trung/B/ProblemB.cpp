#include <iostream>
#include <cstdio>

using namespace std;
long long n;
long long a[1010];
const long long INF = 1e9+7;
const long long mod = 1e9+7;
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    long long maxD = -INF;
    long long zeroCnt = 0;
    long long numAm = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] < 0) {
            numAm ++;
            maxD = max(maxD, a[i]);
        }
        if(a[i] == 0) {
            zeroCnt++;
        }
    }

    if(zeroCnt > 1) {
        cout << 0 << endl;
        return 0;
    }
    if(zeroCnt == 1) {
        if(numAm%2 == 0) {
            long long Ans = 1;
            for(int i = 1; i <= n; i ++) {
                if(a[i] == 0) continue;
                Ans = (Ans * a[i] + mod*mod) % mod;
            }
            cout << Ans << endl;
        }
        else cout << 0;
        return 0;
    }
    if(numAm%2 == 0) {
        long long Ans = 1;
        for(int i = 1; i <= n; i ++) {
            Ans = (Ans * a[i] + mod*mod) % mod;
        }
        cout << Ans << endl;
    } else {
        long long Ans = 1;
        for(int i = 1; i <= n; i ++) {
            if(a[i] == maxD) {
                maxD = INF;
                continue;
            } else {
                Ans = (Ans * a[i] + mod*mod) % mod;
            }
        }        
        cout << Ans;
    }
    return 0;
}