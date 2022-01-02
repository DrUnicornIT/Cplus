#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
#define mod 1000000007
#define fs first
#define sc second
using namespace std;
int hashs[5][100][maxn],f,n,len[100],res,power[2][maxn],maxl,base[2];
typedef pair<int,int> II;
typedef pair<II,int> III;
char s[100][maxn];
bool cmp (const III &a,const III &b)
{
    if (a.fs.fs!=b.fs.fs) return a.fs.fs<b.fs.fs;
    else if (a.fs.sc!=b.fs.sc) return a.fs.sc<b.fs.sc;
    return a.sc<b.sc;
}
II get(int k,int i,int j)
{
    int tmp1=(hashs[0][k][j]-((ll)hashs[0][k][i-1]*power[0][j-i+1])%mod+mod)%mod;
    int tmp2=(hashs[1][k][j]-((ll)hashs[1][k][i-1]*power[1][j-i+1])%mod+mod)%mod;
    II tmp=II(tmp1,tmp2);
    return tmp;
}
int check(int m)
{
    III q[maxn];
    int dem=0;
    for (int k=1; k<=n; k++)
    {
        for (int i=m; i<=len[k]; i++)
        {
            q[++dem]=III(get(k,i-m+1,i),k);
        }
    }
    III trc=III(II(-1,-1),-1);
    int cnt=1;
    sort(q+1,q+dem+1,cmp);
    for (int i=1; i<=dem; i++)
    {
        if (q[i].fs==trc.fs)
        {
            if (q[i].sc==trc.sc) continue;
            cnt++;
            trc.sc=q[i].sc;
            if (cnt==f) return 1;
        }
        else
        {
            cnt=1;
            trc=q[i];
        }
    }
    if (cnt==f) return 1;
    return 0;
}
int main()
{
    freopen("Problem2.inp","r",stdin);
    freopen("Problem2.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>f;
    power[0][0]=1;
    power[1][0]=1;
    base[0]=26;
    base[1]=101;
    for (int i=1; i<=n; i++)
    {
        cin>>(s[i]+1);
        len[i]=strlen(s[i]+1);
        maxl=max(maxl,len[i]);
    }
    for (int i=1; i<=maxl; i++)
    {
        power[0][i]=((ll)power[0][i-1]*base[0])%mod;
        power[1][i]=((ll)power[1][i-1]*base[1])%mod;
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=len[i]; j++)
        {
            hashs[0][i][j]=((ll)hashs[0][i][j-1]*base[0]+s[i][j]-'A')%mod;
            hashs[1][i][j]=((ll)hashs[1][i][j-1]*base[1]+s[i][j]-'A')%mod;
        }
    }
    res=1;
    int l=1,r=maxl;
    while(l<=r)
    {
        int m=(l+r)/2;
        if (check(m))
        {
            res=m;
            l=m+1;
        }
        else r=m-1;
    }
    cout<<res;
    return 0;
}
