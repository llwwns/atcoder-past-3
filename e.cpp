#include <iostream>
#include <forward_list>
#include <vector>
using namespace std;
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<forward_list<int>> g(n);
    vector<int> colors(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;v--;
        g[u].push_front(v);
        g[v].push_front(u);
    }
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }
    for (int i = 0; i < q; i++) {
        int c, x;
        cin >> c >> x;
        x--;
        cout << colors[x] << endl;
        if (c == 1) {
            for (auto j: g[x]) {
                colors[j] = colors[x];
            }
        } else {
            cin >> colors[x];
        }
    }
}
