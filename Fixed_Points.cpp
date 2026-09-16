#include <iostream>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == n - 1) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}