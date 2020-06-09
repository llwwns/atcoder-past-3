#include <iostream>
using namespace std;
const int SAME = 1;
const int CI = 2;
const int DIFF = 3;
int main() {
    string a, b;
    cin >> a >> b;
    int res = SAME;
    for (int i = 0; i < 3; i++) {
        if (a[i] == b[i]) {
            continue;
        }
        if (a[i] >= 'A' && a[i] <= 'Z') {
            a[i] = a[i] - 'A' + 'a';
        }
        if (b[i] >= 'A' && b[i] <= 'Z') {
            b[i] = b[i] - 'A' + 'a';
        }
        if (a[i] == b[i]) {
            res = CI;
            continue;
        }
        res = DIFF;
        break;
    }
    switch(res) {
        case SAME:
            cout << "same" << endl;
            break;
        case CI:
            cout << "case-insensitive" << endl;
            break;
        case DIFF:
            cout << "different" << endl;
            break;
    }
}
