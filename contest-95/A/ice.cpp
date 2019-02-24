#include <bits/stdc++.h>
using namespace std;

struct DSU {

    vector<int> rank, parent;
    int size, n_sets; // size is number of nodes regardless of which set they are in

    DSU(int _size) {
        rank = vector<int>(_size);
        parent = vector<int>(_size);
        size = _size;
        n_sets = _size;
        for (int i = 0; i < _size; i++) {
            rank[i] = 1;
            parent[i] = 0;
        }
    }
    
    int find(int target) {
        int prev = target;
        while (parent[target] != target) {
            target = parent[target];
        }
        compress(prev, target);
        return target;
    }
    
    void compress(int start, int root) {
        while (parent[start] != root) {
            int temp = parent[start];
            parent[start] = root;
            start = temp;
        }
    }

    bool merge(int a, int b) {
        int a_ptr = find(a);
        int b_ptr = find(b);
        if (a_ptr == b_ptr) {
            return false;
        }
        n_sets--;
        if (rank[a_ptr] <= rank[b_ptr]) {
            rank[b_ptr]++;  // join by size uses += rank[a_ptr]
            parent[a_ptr] = b_ptr;
        }
        else {
            rank[a_ptr]++;
            parent[b_ptr] = a_ptr;
        }
        return true;
    }
};

int main() {
    
    int N; cin >> N;
    DSU dsu = DSU(N);
    
    map<int, set<pair<int, int>>> x_to_set;
    map<int, set<pair<int, int>>> y_to_set;
    map<pair<int, int>, int> coord_to_djs_idx;

    for (int n = 0; n < N; n++) {
        int X, Y; cin >> X >> Y;
        pair<int, int> coord = {X, Y};

        x_to_set[X].insert(coord);
        y_to_set[Y].insert(coord);
        
        coord_to_djs_idx[coord] = n;
    }

    for (auto it = x_to_set.begin(); it != x_to_set.end(); it++) {
        pair<int, int> root_coord = *(it->second.begin());
        int root_pair_idx = coord_to_djs_idx[root_coord];

        for (pair<int, int> coord : it->second) {
            int extra_pair_idx = coord_to_djs_idx[coord];
            dsu.merge(root_pair_idx, extra_pair_idx);
        }
    }

    for (auto it = y_to_set.begin(); it != y_to_set.end(); it++) {
        pair<int, int> root_coord = *(it->second.begin());
        int root_pair_idx = coord_to_djs_idx[root_coord];

        for (pair<int, int> coord : it->second) {
            int extra_pair_idx = coord_to_djs_idx[coord];
            dsu.merge(root_pair_idx, extra_pair_idx);
        }
    }

    cout << (dsu.n_sets - 1) << endl;
}
