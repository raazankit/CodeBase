#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Checks if the product of u and v is within K distance of any square X^2
bool is_valid(int u, int v, int K) {
    int P = u * v;
    int X1 = max(1, (int)sqrt(P)); // Closest positive integer root
    int X2 = X1 + 1;
    
    return abs(P - X1 * X1) <= K || abs(P - X2 * X2) <= K;
}

// DFS to find a perfect matching among all UNUSED vertices
bool dfs_perfect_matching(int paired_count, int target_pairs, vector<bool>& used, const vector<vector<bool>>& adj, vector<pair<int, int>>& ans_pairs) {
    if (paired_count == target_pairs) return true;

    int n = used.size() - 1;
    int best_u = -1;
    int min_deg = n + 1;

    // 1. Find the vertex with the minimum degree (MRV Heuristic)
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            int deg = 0;
            for (int j = 1; j <= n; j++) {
                if (!used[j] && adj[i][j]) deg++;
            }
            
            if (deg == 0) return false; // Impossible to perfectly match if an isolated vertex exists
            
            if (deg < min_deg) {
                min_deg = deg;
                best_u = i;
            }
        }
    }

    if (best_u == -1) return false;

    // 2. Warnsdorff's Heuristic: Try neighbors with the fewest options first to fail fast
    vector<pair<int, int>> options;
    for (int v = 1; v <= n; v++) {
        if (!used[v] && adj[best_u][v]) {
            int deg = 0;
            for (int j = 1; j <= n; j++) {
                if (!used[j] && adj[v][j]) deg++;
            }
            options.push_back({deg, v});
        }
    }
    
    sort(options.begin(), options.end());

    // 3. Backtrack through valid options
    for (auto opt : options) {
        int v = opt.second;
        
        used[best_u] = true;
        used[v] = true;
        ans_pairs.push_back({best_u, v});

        if (dfs_perfect_matching(paired_count + 1, target_pairs, used, adj, ans_pairs)) {
            return true;
        }

        // Undo choice if it didn't lead to a solution
        ans_pairs.pop_back();
        used[best_u] = false;
        used[v] = false;
    }
    
    return false;
}

void solve() {
    int N, K;
    cin >> N >> K;
    
    vector<vector<bool>> adj(N + 1, vector<bool>(N + 1, false));
    
    // Build adjacency matrix for valid pairs
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (is_valid(i, j, K)) {
                adj[i][j] = true;
                adj[j][i] = true;
            }
        }
    }
    
    if (N % 2 == 0) {
        // Even N: Find a perfect matching for all vertices
        vector<bool> used(N + 1, false);
        vector<pair<int, int>> ans_pairs;
        
        if (dfs_perfect_matching(0, N / 2, used, adj, ans_pairs)) {
            for (auto p : ans_pairs) {
                cout << p.first << " " << p.second << " ";
            }
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
    } else {
        // Odd N: Exactly one vertex must be left isolated.
        // Try isolating each vertex one by one and finding a perfect matching for the rest.
        bool found = false;
        for (int ignored = 1; ignored <= N; ignored++) {
            vector<bool> used(N + 1, false);
            used[ignored] = true; // Pretend it's already used so it gets skipped
            vector<pair<int, int>> ans_pairs;
            
            if (dfs_perfect_matching(0, N / 2, used, adj, ans_pairs)) {
                for (auto p : ans_pairs) {
                    cout << p.first << " " << p.second << " ";
                }
                cout << ignored << "\n"; // Print the isolated vertex at the end
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << -1 << "\n";
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        solve();
    }
    
    return 0;
}