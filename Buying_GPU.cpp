#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long X, Y, Z;
    cin >> X >> Y >> Z;
    
    if (Y >= Z) {
        cout << -1 << "\n";
    } else {
        long long net_gain = Z - Y;
        long long months = (X + net_gain - 1) / net_gain;
        cout << months << "\n";
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
