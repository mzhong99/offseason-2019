#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    while (not (a == 0 and b == 0)) {
        cout << (a + b) << endl;
        cin >> a >> b;
    }
    return 0;
}
