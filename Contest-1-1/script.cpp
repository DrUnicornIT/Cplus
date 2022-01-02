#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    prepareOpts(argc, argv);
    freopen("scipt.out", "w", stdout);
    for(int i = 1; i <= 20; i ++) {
        cout << "generator "<<rnd.next("[a-z]{6,6}") <<" -n=" << 70 <<"> $" << endl;
    }
}
