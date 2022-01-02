#include <bits/stdc++.h>
#define maxn 100009
#define Task ""
#define vt vector
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define ll long long
#define mod 1000000007

using namespace std;
int n, a[maxn];
vector<int> c(maxn);

void nhap()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] *= -1;
}

int max_seq()
{
    int re = 0;
    c[0] = -mod;
    for (int i = 1; i <= n; i++)
    {
        int m = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
        c[m] = a[i], re = max(re, m);
    }
    return re;
}

void solve()
{
    cout << max_seq();
}

int main()
{
    freopen("Problem1.inp", "r", stdin);
    freopen("Problem1.out", "w", stdout);
    nhap();
    solve();
    return 0;
}
