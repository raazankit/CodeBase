#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Write your code for a single test case here
    int N;
    cin>>N;
    vector<int> arr(N);
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    int odd=0,even=0;
    for(int i=0;i<N;i++) {
        if(arr[i]%2==0) {
            even++;
        } else {
            odd++;
        } 
    }
    if(odd==even) {
        cout << 2*odd << "\n";
    } else {
        cout << min(odd,even)*2 + 1 << "\n";
    }

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
