#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long N;
    cin >> N;
    
    if (N % 3 == 0) {
        cout << 0 << "\n";
    } else if (N % 3 == 2) {
        cout << 1 << "\n";
    } else {
        long long next_multiple_of_5 = N + (5 - (N % 5));
        
        if (next_multiple_of_5 % 3 == 0) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
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
}