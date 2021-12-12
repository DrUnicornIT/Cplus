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
    // writegen(25, 1000);
    // writegen(25, 100000);
    int limit = opt<int> ("n");
    int n = rnd.next(1, limit);
    cout << n << endl;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= 2; j ++) {

            cout << rnd.next(1, 100000) << " " << rnd.next(1, 100000) << " ";
        }
        cout << rnd.next(1, 100000) << " " << rnd.next(1, 100000);
        cout << endl;
    }
    int Q = rnd.next(1, limit)
    cout << Q << endl;
    for(int i = 1; i <= n; i ++) {
        if(rnd.next(0, 1)) {
            cout << "x = " << rnd.next(1, 100000) << endl;
        } else {
            cout << "y = " << rnd.next(1, 100000) << endl;
        }
    }
}