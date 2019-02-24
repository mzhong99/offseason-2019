#include <bits/stdc++.h>
using namespace std;


int main() {
    
    int R, C; cin >> R >> C;
    
    bool board[R + 2][C + 2];
    bool seen[R + 2][C + 2];
    int sets[R + 2][C + 2];

    string line;
    
    for (int r = 1; r <= R; r++) {
        cin >> line;
        for (int c = 1; c <= C; c++) {
            board[r][c] = line[c] == '1';
            seen[r][c] = false;
            sets[r][c] = -1;
        }
    }

    for (int r = 0; r < R + 2; r++) {
        seen[r][0] = true;
        sets[r][0] = 0;
        seen[r][C + 1] = true;
        sets[r][C + 1] = 0;
    }

    for (int c = 0; c < C + 2; c++) {
        seen[0][c] = true;
        sets[0][c] = 0;
        seen[R + 1][c] = true;
        sets[R + 1][c] = 0;
    }

    int N; cin >> N;
    int r1, c1, r2, c2;

    vector<pair<pair<int, int>, pair<int, int>>> queries;
    for (int n = 0; n < N; n++) {
        cin >> r1 >> c1 >> r2 >> c2;
        queries.push_back({{r1, c1}, {r2, c2}});
    }
    
    int set_label = 1;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            
            if (seen[r][c]) continue;
            
            sets[r][c] = set_label;
            seen[r][c] = true;

            stack<pair<int, int>> dfs;
            dfs.push({r, c});

            while (!dfs.empty()) {
                
                pair<int, int> current = dfs.top(); dfs.pop();
                bool current_color = board[current.first][current.second];

                vector<pair<int, int>> neighbors = {
                    { current.first - 1, current.second     },
                    { current.first + 1, current.second     },
                    { current.first    , current.second - 1 },
                    { current.first    , current.second + 1 }
                };
                
                for (auto& neighbor : neighbors) {
                    
                    bool neighbor_color = board[neighbor.first][neighbor.second];
                    if (neighbor_color != current_color) continue;
                    
                    if (!seen[neighbor.first][neighbor.second]) {
                        seen[neighbor.first][neighbor.second] = true;
                        sets[neighbor.first][neighbor.second] = set_label;
                        dfs.push(neighbor);
                    }
                }
            }

            set_label++;
        }
    }

    for (int r = 0; r < R + 2; r++) {
        for (int c = 0; c < C + 2; c++) {
             cout << sets[r][c];
        }
        cout << endl;
    }

    for (auto query : queries) {
        
        pair<int, int> source = query.first;
        pair<int, int> dest = query.second;

        int source_set_label = sets[source.first][source.second];
        int dest_set_label = sets[dest.first][dest.second];

        cout << source_set_label << " " << dest_set_label << endl;
        
        string ans = "neither";
        
        if (source_set_label == dest_set_label) {
            ans = board[source.first][source.second] ? "decimal" : "binary";
        }

        cout << ans << endl;
    }
}
