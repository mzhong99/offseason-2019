#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W; cin >> H >> W;
    double L = -1;
    double R = -1;
    double moment = 0;
    double mass = 0;
    bool odd_skip_needed = W % 2 == 1;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            char c; cin >> c;
            moment += c == '.' ? 0 : 1;
            mass += c == '.' ? 0 : 1;
            if (h + 1 == H) {
                if (c != '.' and L == -1) {
                    L = w;
                }
                if (c != '.') {
                    R = w;
                }
            }
        }
    }
    if (mass == 0) {
        cout << "balanced" << endl;
        return 0;
    }
    double x_cm = moment / mass;
    if (abs(x_cm - L) < 0.00001 or abs(x_cm - R) < 0.00001) {
        cout << "balanced" << endl;
        return 0;
    }
    if (x_cm < L) {
        cout << "left" << endl;
    }
    else if (x_cm > R) {
        cout << "right" << endl;
    }
    else {
        cout << "balanced" << endl;
    }
    return 0;
}
