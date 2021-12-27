#include <bits/stdc++.h>

using namespace std;
int T;
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> T;
    while(T --) {
        string x;
        cin >> x;
        int Ans = 0;
        x += '@';
        for(int i = 0; i < (int)x.size() - 1; i ++) {
            if(x[i] == '0' && x[i + 1] == '1') {
                i++;
                continue;
            }
            if(x[i] == '1' && x[i + 1] == '0') {
                i++;
                continue;
            }
            if(x[i] == '0') continue;
            Ans ++;
        }
        cout << Ans << endl;
    }
}