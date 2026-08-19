#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Write your code for a single test case here
    int N;
    cin >> N;
    string s;
    cin >> s;
    bool isEasy = true;
    int count = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            count = 0;
        } else {
            count++;
        }
        if(count >= 4) {
            isEasy = false;
            break;
        }
    }
    if(isEasy) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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