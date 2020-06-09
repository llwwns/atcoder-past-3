#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(n, 0);
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        auto p = upper_bound(c.begin(), c.end(), a, [](int a, int b){
                return a > b;
        });
        if (p == c.end()) {
            cout << -1 << endl;
        } else {
            int j = p - c.begin();
            cout << j + 1 << endl;
            c[j] = a;
        }
    }
}
