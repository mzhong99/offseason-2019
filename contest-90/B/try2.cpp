#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> buffer;
    int N; cin >> N;
    for (int n = 0; n < 2 * N; n++) {
        int s; cin >> s;
        buffer.push_back(s);
    }
    stack<int> start, help;
    for (auto it = buffer.rbegin(); it != buffer.rend(); it++) {
        start.push(*it);
    }
    int steps = 0;
    while (!start.empty()) {
        help.push(start.top()); start.pop();
        steps++;
        while (!help.empty() && !start.empty()) {
            if (help.top() == start.top()) {
                steps++;
                help.pop(); start.pop();
            }
            else {
                break;
            }
        }
    }
    if (start.empty() && help.empty()) {
        cout << steps << endl;
    }
    else {
        cout << "impossible" << endl;
    }
}
