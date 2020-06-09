#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<bitset<26>> a(n);
    for (auto &b: a) {
        b.reset();
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (auto c: s) {
            a[i].set(c - 'a');
        }
    }
    vector<char> ret(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (i > (n - 1) - i) {
            ret[i] = ret[(n - 1) - i];
        } else {
            auto b = a[i] & a[(n - 1) - i];
            for (int j = 0; j < 26; j++) {
                if (b[j]) {
                    ret[i] = j + 'a';
                    break;
                }
            }
            if (ret[i] == 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ret.data() << endl;
}
