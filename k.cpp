#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *next, *prev;
    Node(int v): val(v), next(nullptr), prev(nullptr) {
    }
    Node(int v, Node* n, Node* p): val(v), next(n), prev(p) {
    }
};

struct List {
    Node* head;
    Node* tail;
    List(): head(nullptr), tail(nullptr) {
    }
    ~List() {
        while (head != nullptr) {
            auto t = head;
            head = t->next;
            delete t;
        }
    }

};
int main() {
    int n, q;
    cin >> n >> q;
    vector<List> v(n);
    vector<Node*> mp(n);
    vector<int> r(n);
    for(int i = 0; i < n; i++) {
        v[i].head = v[i].tail = new Node(i);
        mp[i] = v[i].head;
    }
    for (int i = 0; i < q; i++) {
        int f, t, x;
        cin >> f >> t >> x;
        f--;
        t--;
        x--;
        auto n = mp[x];
        auto m = v[f].tail;
        v[f].tail = n->prev;
        n->prev = nullptr;
        if (v[f].tail == nullptr) {
            v[f].head = nullptr;
        } else {
            v[f].tail->next = nullptr;
        }
        if (v[t].tail == nullptr) {
            v[t].head = n;
            v[t].tail = m;
        } else {
            v[t].tail->next = n;
            n->prev = v[t].tail;
            v[t].tail = m;
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto n = v[i].head; n != nullptr; n = n->next) {
            r[n->val] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << r[i] + 1 << endl;
    }
}
