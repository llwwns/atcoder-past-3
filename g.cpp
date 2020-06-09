#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;


int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<vector<bool>> p(405, vector<bool>(405, false));
    for (int i = 0; i < n; i++) {
        int px, py;
        cin >> px >> py;
        p[px + 202][py + 202] = true;
    }
    priority_queue<tuple<int, int, int, int>,
        std::vector<tuple<int, int, int, int>>,
        std::greater<tuple<int, int, int, int>>
        > q;
    auto h = [&](int i, int j) {
        int dx = x - i >= 0 ? x - i : i - x;
        int dy = y - j >= 0 ? y - j : j - y;
        return max(dx, dy);
    };
    q.push(make_tuple(h(0, 0), 0, 0, 0));
    auto check = [&](int nx, int ny, int b) {
        if (nx < -202 || nx > 202 || ny < -202 || ny > 202 || p[nx + 202][ny + 202]) {
            return false;
        }
        if (nx == x && ny == y) {
            return true;
        }
        q.push(make_tuple(h(nx, ny) + b + 1, b + 1, nx, ny));
        p[nx + 202][ny + 202] = true;
        return false;
    };
    while (!q.empty()) {
        int a, cx, cy, b;
        tie(a, b, cx, cy) = q.top();
        q.pop();
        if (
                check(cx + 1, cy + 1, b) ||
                check(cx, cy + 1,b) ||
                check(cx - 1, cy + 1,b) ||
                check(cx + 1, cy,b) ||
                check(cx - 1, cy,b) ||
                check(cx, cy - 1,b)
                ) {
            cout << b + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
