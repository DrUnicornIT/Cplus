#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    cin >> n;
    long long sum = 0;
    while(n--) {
        long long a;
        cin >> a;
        sum += a;
    }
    cout << -sum;
}