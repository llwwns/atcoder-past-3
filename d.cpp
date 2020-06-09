#include <iostream>
#include <array>
using namespace std;

const array<array<string, 5>, 10> table = {{
    {".###",
     ".#.#",
     ".#.#",
     ".#.#",
     ".###"},
    {"..#.",
     ".##.",
     "..#.",
     "..#.",
     ".###"},
    {".###",
     "...#",
     ".###",
     ".#..",
     ".###"},
    {".###",
     "...#",
     ".###",
     "...#",
     ".###"},
    {".#.#",
     ".#.#",
     ".###",
     "...#",
     "...#"},
    {".###",
     ".#..",
     ".###",
     "...#",
     ".###"},
    {".###",
     ".#..",
     ".###",
     ".#.#",
     ".###"},
    {".###",
     "...#",
     "...#",
     "...#",
     "...#"},
    {".###",
     ".#.#",
     ".###",
     ".#.#",
     ".###"},
    {".###",
     ".#.#",
     ".###",
     "...#",
     ".###"}
}};

bool check(const array<string, 5>&a, int i, const array<string, 5> &t) {
    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 5; k++) {
            if (a[k][j + i] != t[k][j]) {
                return false;
            }
        }
    }
    return true;
}

int getNum(const array<string, 5>& a, int i) {
    for (int j = 0; j < 10; j++) {
        if (check(a, i, table[j])) {
            return j;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    array<string, 5> a;
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cout << getNum(a, i * 4);
    }
    cout << endl;
}
