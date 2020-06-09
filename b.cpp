#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<bool> r(n * m, false);
    vector<int> s(m, n);
    for (int i = 0; i < q; i++) {
        int c, a, b;
        cin >> c >> a;
        a--;
        if (c == 1) {
            int t = 0;
            for (int j = 0; j < m; j++) {
                if (r[a * m + j]) {
                    t += s[j];
                }
            }
            cout << t << endl;
        } else {
            cin >> b;
            b--;
            if (!r[a * m + b]) {
                r[a * m + b] = true;
                s[b]--;
            }
        }
    }
}
