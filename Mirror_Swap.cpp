#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Write your code for a single test case here
    int N;
    cin>>N;
    vector<int> arr(2*N);
    for(int i=0;i<2*N;i++) {
        cin>>arr[i];
    }
    int l=0,r=2*N-1;
    long long ans=0;
    while(l < r) {
        ans += max(arr[l], arr[r]);
        l++;
        r--;
    }
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
