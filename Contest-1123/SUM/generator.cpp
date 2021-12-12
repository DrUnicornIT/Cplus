#include "testlib.h"
#include <iostream>
using namespace std;
void writegen(int n, int val) {
    for(int i = 1; i <= n; i ++) {
        cout << "generator " << rnd.next("[a-z]{9}") << " -n=" << val << " > $"<< endl;
    }
}
int main(int argc, char * argv[])
{
    registerGen(argc, argv, 1);
    prepareOpts(argc, argv);
    // freopen("generator.out", "w", stdout);
    // writegen(25, rnd.next(1, 100));
    // writegen(25, rnd.next(101, 10000));
    int n = opt<int> ("n");
    cout << n ;
    for(int i = 1; i <= n; i ++) {
        if(rnd.next(0, 10000)) cout  << " "<< -1;
        else cout  << " "<< rnd.next(-1, n-1);
    }
}