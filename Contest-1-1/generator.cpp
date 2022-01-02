#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    prepareOpts(argc, argv);

    int lim = opt<int>("n");
    int n = rnd.next(1, 100);
    cout << n << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << rnd.next(1, 1000000) << endl;
    }
}
