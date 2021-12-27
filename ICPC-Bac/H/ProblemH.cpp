#include <bits/stdc++.h>

using namespace std;
int n, x;
int Ans;
int A[1000010];
void solve(int i) {
    if(i == n + 1) {
        vector <int> vc[1000];
        for(int j = 1; j <= n; j ++) {
            vc[A[j]].push_back(j);
        }
        for(int j = 1; j <= n; j ++) {
            if(vc[j].size())
        }
    }
    for(int j = 1; j <= n; j ++) {
        A[i] = j;
        solve(i+1);
    }
}
int main() {
    cin >> n >> x;
    solve(1);
    cout << Ans;
}