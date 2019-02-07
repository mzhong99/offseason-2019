#include <bits/stdc++.h>
using namespace std;

//--------------------------------------------------------------------------------

vector<vector<char>> board;
vector<vector<bool>> used;

vector<char> building_word;

unordered_map<string, bool> words;
unordered_set<string> cache;
int max_length = 0;

//--------------------------------------------------------------------------------

int main();
void parse();
void solve();
void validate();

bool is_in_range(pair<int, int>& coord);
void search(int r, int c);
void build_and_check(vector<char>& potential_word);
bool is_in_cache(vector<char>& potential_word);

//--------------------------------------------------------------------------------

int main() {
    parse();
    solve();
    validate();
    return 0;
}

void parse() {

    int H, W; cin >> H >> W;

    for (int h = 0; h < H; h++) {
        
        string s; cin >> s;
        board.push_back(vector<char>());
        used.push_back(vector<bool>());
        
        for (int w = 0; w < W; w++) {
            board[h].push_back(s[w]);
            used[h].push_back(false);
        }
    }

    int C; cin >> C;
    
    for (int c = 0; c < C; c++) {
        
        string s; cin >> s;
        words[s] = false;
        
        if (max_length < s.size()) {
            max_length = s.size();
        }
    }
}

void validate() {
    int found = 0;
    for (auto it = words.begin(); it != words.end(); it++) {
        found += it->second ? 1 : 0;
    }
    cout << found << endl;
}

void solve() {
    
    for (int r = 0; r < board.size(); r++) {
        for (int c = 0; c < board[r].size(); c++) {

            used[r][c] = true;
            building_word.push_back(board[r][c]);

            search(r, c);

            building_word.pop_back();
            used[r][c] = false;
        }
    }
}

bool is_in_range(pair<int, int>& coord) {
    return coord.first  >= 0 && coord.first  < board.size()
        && coord.second >= 0 && coord.second < board[coord.first].size();
}

void search(int r, int c) {
    
    if (building_word.size() > max_length) return;
    if (is_in_cache(building_word)) return;

    build_and_check(building_word);

    vector<pair<int, int>> neighbors = {
        {r - 1, c}, 
        {r + 1, c}, 
        {r, c - 1}, 
        {r, c + 1}
    };

    for (pair<int, int> coord : neighbors) {
        
        if (!is_in_range(coord)) continue;
        if (used[coord.first][coord.second]) continue;

        used[coord.first][coord.second] = true;
        building_word.push_back(board[coord.first][coord.second]);

        search(coord.first, coord.second);

        building_word.pop_back();
        used[coord.first][coord.second] = false;
    }

    cache.insert(string(building_word.begin(), building_word.end()));
}

void build_and_check(vector<char>& potential_word) {
    
    string word = string(potential_word.begin(), potential_word.end());
    
    if (words.find(word) != words.end()) {
        words[word] = true;
    }
}

bool is_in_cache(vector<char>& potential_word) {

    string word = string(potential_word.begin(), potential_word.end());
    return cache.find(word) != cache.end();
}
