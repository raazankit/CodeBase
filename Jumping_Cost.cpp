#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Write your code for a single test case here
    int N;
    cin>>N;
    vector<int> arr(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    long long max_sum = 0;
    long long sum = 0;
    
    
    for (int j = 1; j < N; j++) {
        
        long long current_sum = arr[j] - j + sum;
        
        max_sum = max(max_sum, current_sum);
        
        if (arr[j] > 0) {
            sum += arr[j];
        }
    }
    
    cout << max_sum << "\n";
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
}