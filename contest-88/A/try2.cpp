#include <bits/stdc++.h>
using namespace std;

//--------------------------------------------------------------------------------

vector<string> classmates;
vector<bool> used;
vector<int> order;
unordered_set<string> hate_pairs;

bool has_validation = false;

//--------------------------------------------------------------------------------

int main();
bool parse();

void setup();
void validate();
void cleanup();

//-------------------------------------------------------------------------------- 

int main() {
    
    while (parse()) {
        setup();
        validate();
        cleanup();
    }
}

void setup() {
    used = vector<bool>(classmates.size());
    for (int i = 0; i < used.size(); i++) {
        used[i] = false;
    }
}

void cleanup() {
    
    if (!has_validation) {
        cout << "You all need therapy." << endl;
    }

    classmates = vector<string>();
    used = vector<bool>();
    order = vector<int>();
    hate_pairs = unordered_set<string>();

    has_validation = false;
}

bool parse() {
    
    if (cin.fail()) return false;

    int N; cin >> N;
    
    for (int n = 0; n < N; n++) {
        string mate; cin >> mate;
        classmates.push_back(mate);
    }

    if (cin.fail()) return false;

    int H; cin >> H;

    for (int h = 0; h < H; h++) {
        
        string mate1, mate2;
        cin >> mate1 >> mate2;

        hate_pairs.insert(mate1 + " " + mate2);
        hate_pairs.insert(mate2 + " " + mate1);
    }

    sort(classmates.begin(), classmates.end());
    return true;
}

void validate() {

    if (has_validation) {
        return;
    }
    
    else if (order.size() == classmates.size()) {
        
        for (int m_idx : order) {
            cout << classmates[m_idx] << " ";
        }
        
        cout << endl;
        
        has_validation = true;
    }
    
    else {
        
        for (int m_idx = 0; m_idx < classmates.size(); m_idx++) {
            
            if (!used[m_idx]) {
                
                if (order.size() != 0) {
                    
                    string pairing = classmates[order.back()] + " " + classmates[m_idx];
                    
                    if (hate_pairs.find(pairing) != hate_pairs.end()) {
                        continue;
                    }
                }

                used[m_idx] = true;
                order.push_back(m_idx);
                
                validate();
                
                order.pop_back();
                used[m_idx] = false;
            }
        }
    }
}
