#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    long long ans = 0;
    long long prev_b = 0;
    
    for (int i = 1; i <= n; ++i) {
        long long a;
        cin >> a;
        long long curr_b = (i % 2 != 0) ? a : -a;
        long long diff = curr_b - prev_b;
        if (diff > 0) {
            ans += diff;
        }
        
        prev_b = curr_b;
    }
    long long final_diff = 0 - prev_b;
    if (final_diff > 0) {
        ans += final_diff;
    }
    
    cout << ans << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    
    return 0;
}