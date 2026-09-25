#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Write your code for a single test case here
    int n;
    cin >> n;
    int rev = 0;
    int temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        rev = (rev * 10) + digit;
        temp /= 10; 
    }
    if (rev == n) {
        cout << n << " is a palindrome number." << endl;
    } else {
        cout << n << " is not a palindrome number." << endl;
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
