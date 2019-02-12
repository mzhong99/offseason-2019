#include <bits/stdc++.h>
using namespace std;

int c = 0;
bool pair_happened = false;

int main() {
    stack<int> left, right;
    int N, sock; cin >> N;
    for (int n = 0; n < 2 * N; n++) {
        cin >> sock;
        left.push(sock);
    }
    while (!(left.empty())) {
        right.push(left.top());
        left.pop();
        if (left.empty()) break;
        if (right.top() == left.top()) {
            right.pop(); left.pop();
        }
    }
    if (!left.empty() || !right.empty()) {
        cout << "impossible" << endl;
    }
    else {
        cout << c << endl;
    }
}
