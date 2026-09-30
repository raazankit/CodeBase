#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Write your code for a single test case here
    long long N;
    cin >> N;
    unordered_map<long long,long long> freq;
    long long max_freq = 0;
    for(long long i=0;i<N;i++){
        long long temp;
        cin >> temp;
        long long diff = temp - i;
        freq[diff]++;
        max_freq = max(max_freq,freq[diff]);
    }
    cout << N-max_freq << endl;
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
