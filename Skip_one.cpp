#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long N, K;
    cin >> N >> K;
    vector<long long> arr(N);
    for(long long i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    long long count = 0;
    long long discount = 0; 
    
    for(long long i = 0; i < N; i++) {
        K -= arr[i];
        
        if(arr[i] > discount) {
            discount = arr[i];
        }
        
        if(K + discount >= 0) {
            count++;
        }
        else {
            break;
        }
    }
    cout << count << "\n";
}

int main() {
    // Disables synchronization between C and C++ standard streams for maximum I/O speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long t = 1;
    // Read the number of test cases (Comment this out if the problem only has 1 test case)
    cin >> t; 
    
    while (t--) {
        solve();
    }
    
    return 0;
}// GitHub sync update
