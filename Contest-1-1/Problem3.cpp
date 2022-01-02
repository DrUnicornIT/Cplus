  /*JOKER*/
#include<bits/stdc++.h>
#define maxn 105
#define maxm 1000000007
#define bas 37
 
 
using namespace std;
 
int n, f[5], a[maxn][maxn], res = maxm;
 
 
int main()
{
    freopen("Problem3.inp","r",stdin);
    freopen("Problem3.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin >> n;
    for(int i = 1; i <= 4; i++)
        cin >> f[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) if(i!= j) a[i][j] = maxm;
        else a[i][j] = 0;
 
    int u, v, c;
    while(cin >> u >> v >> c)
        a[u][v] = a[v][u] = c;
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
    for(int u = 1 ; u <= n; u++)
        for(int v = u; v <= n; v++)
            for(int i = 1; i <= 3; i++)
                for(int j = i + 1; j <= 4; j++)
                {
                    int ans = a[f[i]][u] + a[f[j]][u] + a[u][v];
                    for(int k = 1; k <= 4; k++)
                        if(k!= i && k != j) ans += a[f[k]][v];
                    res = min(res, ans);
                }
    cout << res;
}
 