#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> r(n), c(n);
    bool t = false;
    for (int i = 0; i < n; i++) {
        r[i] = i;
        c[i] = i;
    }
    for (int i = 0; i < q; i++) {
        int p, x, y;
        cin >> p;
        switch (p) {
        case 1:
            cin >> x >> y;
            x--;y--;
            swap(r[x], r[y]);
            break;
        case 2:
            cin >> x >> y;
            x--;y--;
            swap(c[x], c[y]);
            break;
        case 3:
            swap(r, c);
            t = !t;
            break;
        case 4:
            cin >> x >> y;
            x--;y--;
            int ax = r[x];
            int ay = c[y];
            if (t) {
                swap(ax, ay);
            }
            cout << ((long long)ax) * n + ay << endl;
        }
    }
}
