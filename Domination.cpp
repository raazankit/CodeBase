#include <iostream>
#include <vector>

using namespace std;

void solve() {
    long long N;
    cin >> N;
    
    vector<vector<int>> adj(N + 1);
    vector<int> deg(N + 1, 0);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    long long leaves = 0;
    vector<long long> leaf_neighbors(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        if (deg[i] == 1) {
            leaves++;
            int neighbor = adj[i][0];
            leaf_neighbors[neighbor]++;
        }
    }

    long long total_sets = (N * (N - 1) / 2) * (N - 2) / 3; 
    long long leaf_edge_sets = leaves * (N - 2);
    long long double_counted = 0;
    
    for (int i = 1; i <= N; i++) {
        if (leaf_neighbors[i] >= 2) {
            double_counted += (leaf_neighbors[i] * (leaf_neighbors[i] - 1)) / 2; 
        }
    }

    long long strict_deg2_sets = 0;
    for (int i = 1; i <= N; i++) {
        if (deg[i] == 2) {
            int u = adj[i][0];
            int v = adj[i][1];
            if (deg[u] >= 2 && deg[v] >= 2) {
                strict_deg2_sets++;
            }
        }
    }

    long long invalid_sets = leaf_edge_sets - double_counted + strict_deg2_sets;
    long long ans = total_sets - invalid_sets;
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}