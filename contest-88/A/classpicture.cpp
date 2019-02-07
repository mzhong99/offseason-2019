#include <bits/stdc++.h>
using namespace std;

bool has_validation;

void validate(vector<string>& classmates, 
              unordered_set<string>& hate_pairs,
              vector<string>& good_ordering,
              vector<bool>& used) {
    
    // done
    if (has_validation) {
        return;
    }

    // found
    if (good_ordering.size() == classmates.size()) {
        for (string& mate : classmates) {
            cout << mate << " ";
        }
        cout << endl;
        has_validation = true;
    }

    // backtrack try
    for (int i = 0; i < classmates.size(); i++) {
        
        if (!used[i]) {

            if (good_ordering.size() != 0) {
                
                string pr = good_ordering.back() + " " + classmates[i];
                
                if (hate_pairs.find(pr) != hate_pairs.end()) {
                    continue;
                }
            }

            used[i] = true;

            good_ordering.push_back(classmates[i]);
            
            validate(classmates, hate_pairs, good_ordering, used);

            used[i] = false;
            good_ordering.pop_back();
        }
    }
}

int main() {
    
    while (!cin.fail()) {
        
        int class_size; cin >> class_size;
        
        vector<string> classmates;
        vector<string> good_ordering;
        
        vector<bool> used(class_size);
        for (int i = 0; i < class_size; i++) {
            used[i] = false;
        }

        unordered_set<string> hate_pairs;

        for (int i = 0; i < class_size; i++) {
            string classmate; cin >> classmate;
            classmates.push_back(classmate);
        }

        if (cin.fail()) {
            break;
        }

        int hate_size; cin >> hate_size;
        
        for (int i = 0; i < hate_size; i++) {

            string hate1, hate2;
            cin >> hate1 >> hate2;
            
            hate_pairs.insert(hate1 + " " + hate2);
            hate_pairs.insert(hate2 + " " + hate1);
        }
        
        sort(classmates.begin(), classmates.end());

        has_validation = false;
        validate(classmates, hate_pairs, good_ordering, used);
        
        if (!has_validation) {
            cout << "You all need therapy." << endl;
        }
    }

    return 0;
}

