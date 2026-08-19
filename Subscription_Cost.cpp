#include <bits/stdc++.h>
using namespace std;

int solve() {
    // Write your code for a single test case here
    int N,X,Y;
    cin>>N>>X>>Y;
    if(N<=3){
        cout<<N*X<<endl;
    }
    else{
        cout<<3*X+(N-3)*Y<<endl;
    }
    return 0;
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