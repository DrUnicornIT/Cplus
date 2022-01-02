#include <stdio.h>
//#include <conio.h>
int n,m,kt[51],dai[51],gia[51];
int d[51][51],flag[51],f[51][53];


int main()
{
    freopen("Problem4.inp","r",stdin);
    freopen("Problem4.out","w",stdout);
    for(int i = 0;i<=50;i++)
    {
        flag[i]=0;
        for(int j = 0;j<=50;j++)
        {
            d[i][j]=0;
            f[i][j]=0;
        }
    }

    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
        scanf("%d",&kt[i]);
    scanf("%d",&m);   
    for(int i = 1;i<=m;i++)
    {
        scanf("%d %d",&dai[i],&gia[i]);
        flag[dai[i]]=i;
    }        
    for(int i = 1;i<=50;i++)
        for(int j = 0;j<=50;j++)
        {
            if(j==0)
            {
                   if( flag[i]!=0)
                d[i][j]=gia[flag[i]];
            }
            else 
            {
                int max=0;
                for(int k = 1;k<=i-1;k++)
                    if(d[k][j-1]+d[i-k][0]>max)
                        max = d[k][j-1]+d[i-k][0];
                d[i][j]=max;
            }
            //if(i==10) printf("%d %d %d\n",j,d[i][j],flag[10]);
        }
    for(int i = 1;i<=n;i++)
        for(int j = 0;j<=52;j++)
        {
            if(i==1)
                f[i][j]=d[kt[i]][j];
            else 
            {
                int max = 0;
                for(int k = 0;k<=j;k++)
                    if(f[i-1][k]+d[kt[i]][j-k]>max)
                        max = f[i-1][k]+d[kt[i]][j-k];
                f[i][j] = max;
            }
        }
    int Max = 0;
    for(int i=0;i<=52;i++)
        if(f[n][i]-i*(i+1)/2>Max)
        {
            Max = f[n][i]-i*(i+1)/2;
           // printf("%d %d %d\n",i,f[n][i],Max);
        }
    printf("%d",Max);
    //getch();
}