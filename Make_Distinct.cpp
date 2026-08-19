#include <bits/stdc++.h>
using namespace std;

void solve() {
   int N;
    long long K;
    cin >> N >> K;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    long long target = A[0];
    long long max_diff = 0;
    long long sum_diff = 0;
    
    for (int i = 0; i < N; ++i) {
        if (A[i] > target) {
            target = A[i];
        }
        long long diff = target - A[i];
        max_diff = max(max_diff, diff);
        sum_diff += diff;
        target++;
    }
    
    long long ans = max(max_diff, (sum_diff + K - 1) / K);
    cout << ans << "\n";
    
    
}

int main() {
    // Disables synchronization between C and C++ standard streams for maximum I/O speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // Read the number of test cases (Comment this out if the problem only has 1 test case)
    cin >> t; 
    
    while (t--) {
        solve();
    }
    
    return 0;
}// GitHub sync update
