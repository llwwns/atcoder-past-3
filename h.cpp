#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
    int n, l;
    cin >> n >> l;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;
    vector<int> t(l + 1, 0);
    for (int i = 1; i <= l; i++) {
        t[i] = t[i-1] + t1;
        if (i > 1) {
            int x = t[i-2] + t1 + t2;
            if (x < t[i]) {
                t[i] = x;
            }
        }
        if (i > 3) {
            int x = t[i-4] + t1 + t2 * 3;
            if (x < t[i]) {
                t[i] = x;
            }
        }
        if (s.find(i) != s.end()) {
            t[i] += t3;
        }
    }
    int r = min(t[l], t[l - 2] + t1 + t2);
    r = min(r, t[l - 1] + (t1 + t2) / 2);
    r = min(r, t[l - 2] + (t1 + t2) / 2 + t2);
    if (l >= 3) {
        r = min(r, t[l - 3] + (t1 + t2) / 2 + t2 * 2);
    }
    if (l >= 4) {
        r = min(r, t[l - 4] + t1 + t2 * 3);
    }
    cout << r << endl;
}
