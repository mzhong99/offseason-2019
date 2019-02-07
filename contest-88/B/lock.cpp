#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int R; cin >> R;
    vector<int> rotations;
    
    for (int r = 0; r < R; r++) {
        int rotation; cin >> rotation;
        rotations.push_back(rotation);
    }
    
    for (int mask = 0; mask < (1 << R); mask++) {
        
        int final_pos = 0;
        
        for (int curr_bit_mask = 1, index = 0; 
            curr_bit_mask < (1 << R); 
            curr_bit_mask <<= 1, index++) {

            final_pos += rotations[index] * (curr_bit_mask & mask ? 1 : -1);
        }

        if (final_pos % 360 == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    
    cout << "NO" << endl;
    return 0;
}
