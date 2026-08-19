#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Write your code for a single test case here
    int N,M,X;
    cin>>N>>M>>X;
    int rows = (X-1)/M+1;
    
    int min_rows = min(rows,N-rows+1);
    cout<<min_rows<<"\n";
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
