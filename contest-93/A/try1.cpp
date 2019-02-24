#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E; cin >> V >> E;
    int edges_if_fully_connected = V - 1;
    int edges_if_complete = V * (V - 1) / 2;
    int min_isolated_vertices = -1;
    int max_isolated_vertices = -1;
    if (E >= edges_if_fully_connected) {
        min_isolated_vertices = 0;
    }
    else {
        min_isolated_vertices = V - (E + 1);
    }

    int vertices_connected_if_dense = ((int)((1 + sqrt(1 + (8 * E))) * 0.5));
    if (E >= edges_if_complete) {
        max_isolated_vertices = 0;
    }
    else {
        max_isolated_vertices = V - vertices_connected_if_dense;
    }
    cout << min_isolated_vertices << " " << max_isolated_vertices << endl;
}
