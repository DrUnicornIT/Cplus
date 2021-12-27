#include <iostream>
using namespace std;

struct Vector {
    
    double x;
    double y;
    Vector (double _x = 0, double _y = 0){
        x = _x;
        y = _y;
    }
void printVector(){
        cout << x << " " << y << endl;
    }
};

Vector addVector(Vector v1, Vector v2)
{
    // Them code cua ban o day
   Vector sum;
   sum.x=v1.x+v2.x;
   sum.y=v1.y+v2.y;
}



int main()
{
Vector Tong;

return 0;



    // Them code cua ban o day
}

#include <iostream>

using namespace std;

int n;
int A[1000];
bool Tang, Giam;
int main() {

    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> A[i];
        if(i >= 2 && A[i] > A[i-1]) {
            if(A[i] > A[i-1]) {
                Tang = 1;
            }
            if(A[i] < A[i-1]) {
                Giam = 1;
            }
        }
    }
    if(Tang && Giam) {
        cout << "khac";
    } else {
        if(Tang) {
            cout << "tang";
            return 0;
        }
        if(Giam) {
            cout << "giam";
            return 0;
        }
        cout << "khac";
        return 0;
    }
    
    return 0;
}