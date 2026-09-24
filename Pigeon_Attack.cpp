#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Write your code for a single test case here
    int N,K;
    cin>>N>>K;
    int blocks = N/(K-1);
    int rem = N%(K-1);
    if(rem==0){
        cout<<(blocks*K) -1<<endl;
    }
    else{
        cout<<blocks*(K)+rem<<endl;
    }
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
