#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the 0-indexed position of the MSB
int get_msb(long long n) {
    if (n == 0) return -1;
    return 63 - __builtin_clzll(n); 
}

void solve() {
    int n;
    cin >> n;
    
    vector<int> msb_counts(64, 0);
    int max_subset_size = 0;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        
        if (x > 0) {
            int msb = get_msb(x);
            msb_counts[msb]++;
            max_subset_size = max(max_subset_size, msb_counts[msb]);
        }
    }

    cout << max_subset_size << "\n";
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}