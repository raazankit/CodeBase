#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Write your code for a single test case here
    int N,K;
    cin >> N >> K;
    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for(int i=0;i<N;i++){
        if(arr[i] <= K) {
            cout << "1";
            K -= arr[i];
        } else {
            cout << "0";
        }
    }
    cout<< endl;
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
