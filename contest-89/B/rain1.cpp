#include <bits/stdc++.h>
using namespace std;

int main() {
    string line; cin >> line;
    vector<int> prefix;
    prefix.push_back(line[0] == 'R' ? 1 : -1);
    for (int i = 1; i < line.length(); i++) {
        prefix.push_back(prefix.back() + (line[i] == 'R' ? 1 : -1));
    }
    int low = prefix.back();
    int high = prefix.back();
    int low_idx = prefix.size() - 1;
    int high_idx = prefix.size() - 1;
    for (int i = prefix.size() - 1; i >= 0; i--) {
        if (prefix[i] < low) {
            low = prefix[i];
            low_idx = i;
        }
        if (prefix[i] > high) {
            high = prefix[i];
            high_idx = i;
        }
    }
    cout << min(low_idx, high_idx) << " " << max(low_idx, high_idx) << endl;
}
