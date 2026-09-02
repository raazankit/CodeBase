#include <iostream>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    
    long long max_rounds = 3 * (n / 2) + 1;
    
    cout << max_rounds << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    
    return 0;
}