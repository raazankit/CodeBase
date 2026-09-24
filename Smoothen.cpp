#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSorted(const vector<long long>& A) {
    for (size_t i = 0; i < A.size() - 1; ++i) {
        if (A[i] > A[i+1]) {
            return false;
        }
    }
    return true;
}

bool isValid(long long X, const vector<long long>& A) {
    long long S = 0;
    long long prev = -1;
    
    for (size_t i = 0; i < A.size(); ++i) {
        long long current_val;
        
        if (A[i] >= X) {
            S += (A[i] - X);
            current_val = X;
        } else {
            long long needed = X - A[i];
            long long take = min(S, needed);
            S -= take;
            current_val = A[i] + take;
        }
        
        if (current_val < prev) {
            return false;
        }
        prev = current_val;
    }
    
    return true;
}

void solve() {
    int N;
    cin >> N;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    if (isSorted(A)) {
        cout << -1 << "\n";
        return;
    }
    
    long long low = 1, high = 1e9;
    long long ans = -1;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        if (isValid(mid, A)) {
            ans = mid;         
            low = mid + 1;
        } else {
            high = mid - 1;   
        }
    }
    
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}