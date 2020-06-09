#include <iostream>
using namespace std;
const int SAME = 1;
const int CI = 2;
const int DIFF = 3;
int main() {
    const long long x = 1000000000;
    int a, r, n;
    cin >> a >> r >> n;
    n--;
    long long c = 1, t = r;
    while (n > 0) {
        if (c > x || t > x) {
            break;
        }
        if ((n & 1) == 1) {
            c = c * t;
        }
        t = t * t;
        n >>= 1;
    }
    c = c * a;
    if ((t > x && n > 0) || c > x) {
        cout << "large" << endl;
    } else {
        cout << c << endl;
    }
}
