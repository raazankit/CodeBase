#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Write your code for a single test case here
    string s;
    cin >> s;
    if(s.length() > 10) {
        cout << s[0] << s.length() - 2 << s[s.length() - 1] << "\n";
    } else {
        cout << s << "\n";
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
