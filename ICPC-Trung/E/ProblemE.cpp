#include <iostream>
#include <cstdio>
#include <stdio.h>

using namespace std;
int Test;
struct Tnode
{
    long long x, y;
} Point[10];

long long ccw(Tnode a, Tnode b, Tnode c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> Test;
    while (Test--)
    {
        for (int i = 1; i <= 4; i++)
        {
            cin >> Point[i].x >> Point[i].y;
        }
        bool tf = 0;
        for (int i = 1; i <= 4; i++)
        {
            for (int j = i + 1; j <= 4; j++)
            {
                for (int k = 1; k <= 4; k++)
                {
                    if (k == i || k == j)
                        continue;
                    for (int l = 1; l <= 4; l++)
                    {
                        if (l == i || l == j || l == k)
                            continue;
                        if (ccw(Point[i], Point[j], Point[k]) * ccw(Point[i], Point[j], Point[l]) < 0 && ccw(Point[i], Point[k], Point[l]) * ccw(Point[j], Point[k], Point[l]) < 0)
                        {
                            tf = 1;
                        }
                    }
                }
            }
        }
        if (tf == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}