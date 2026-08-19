#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<long long> arr(N);
    
    long long total_chocolates = 0;
    long long odd_count = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        total_chocolates += arr[i];
        if (arr[i] % 2 != 0) {
            odd_count++;
        }
    }
    
    if (total_chocolates % 2 == 0) {
        cout << (total_chocolates - odd_count) + (odd_count / 2) << "\n";
    } else {
        cout << (odd_count / 2) << "\n";
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