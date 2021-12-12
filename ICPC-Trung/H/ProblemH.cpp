#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
const double PI = 3.1415926535897932384626433832795; // acos((db)-1); atan(-1.0);

struct Point {
    double x, y;
} A[4];
double R;
double pre;
double len (Point a, Point b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double pw2 (double x) {
    return x*x;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    for(int i = 1; i <= 3; i ++)  {
        cin >> A[i].x >> A[i].y;
    }
    cin >> R >> pre;
    double a = -(A[2].y-A[1].y);
    double b = A[2].x-A[1].x;
    double c = -(a*A[1].x+b*A[1].y);

    if(pw2(R)*(pw2(a)+pw2(b)) <= pw2(abs(a*A[3].x + b*A[3].y + c))) {
        cout << "NO" << endl;
        return 0;
    } else {
        double h = abs(a*A[3].x + b*A[3].y + c) / sqrt(pw2(a)+pw2(b));
        double tile = acos(h/R) * pw2(R) - (h*sqrt(pw2(R)-pw2(h)));
        double cur = (tile / (pw2(R)*PI)) * 100;
        if(abs(cur - pre) <= (double)5) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}