#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long N;
    cin >> N;
    vector<long long> arr(N);
    for (long long i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long long min_u = 4e18;  
    long long max_u = -4e18; 
    bool possible = true;
    bool has_mismatch = false;

    for (long long i = 0; i < N / 2; i++) {
        long long left = arr[i];
        long long right = arr[N - 1 - i];

        if (left != right) {
            has_mismatch = true;
            
            if (abs(left - right) != 2) {
                possible = false;
                break;
            }
            
            long long u = min(left, right);
            
            min_u = min(min_u, u);
            max_u = max(max_u, u);
        }
    }

    if (!possible) {
        cout << "No\n";
        return;
    }

    if (!has_mismatch) {
        cout << "Yes\n";
        return;
    }

    if (max_u <= min_u + 1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}