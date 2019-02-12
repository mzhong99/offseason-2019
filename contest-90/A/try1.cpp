#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> costumes;
    int N; cin >> N;
    string costume;
    for (int n = 0; n < N; n++) {
        cin >> costume;
        if (costumes.find(costume) == costumes.end()) {
            costumes[costume] = 0;
        }
        costumes[costume] -= 1;
    }
    priority_queue<pair<int, string>> pq;
    for (auto kv = costumes.begin(); kv != costumes.end(); kv++) {
        pq.push({kv->second, kv->first});
    }
    vector<string> buff;
    int target = pq.top().first;
    while (!pq.empty() && pq.top().first == target) {
        buff.push_back(pq.top().second);
        pq.pop();
    }
    sort(buff.begin(), buff.end());
    for (auto& val : buff) {
        cout << val << endl;
    }
}
