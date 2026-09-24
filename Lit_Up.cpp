#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    
    vector<long long> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    long long min_cost = 1e18; 
    
    deque<int> dq;
    int current_R = -1;
    
    int limit = min(N - 2, K); 
    
    for(int i = 0; i <= limit; i++) {
        int L = max(i + 1, N - 1 - K);
        int R = min(N - 1, i + 2 * K + 1);
        
        if (L > R) continue;
        
        while (current_R < R) {
            current_R++;
            while (!dq.empty() && arr[dq.back()] >= arr[current_R]) {
                dq.pop_back();
            }
            dq.push_back(current_R);
        }
        
        while (!dq.empty() && dq.front() < L) {
            dq.pop_front();
        }
        
        if (!dq.empty()) {
            min_cost = min(min_cost, arr[i] + arr[dq.front()]);
        }
    }
    
    if (min_cost == 1e18) {
        cout << -1 << "\n";
    } else {
        cout << min_cost << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t; 
    
    while (t--) {
        solve();
    }
    
    return 0;
}