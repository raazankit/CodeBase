#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<long long, int>> v;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
            v.push_back({a[i], i});
        }
    }

    sort(v.rbegin(), v.rend());

    for (auto p : v) {
        int i = p.second;
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
            a[i - 1] = a[i];
            a[i + 1] = a[i];
        }
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    
    cout << sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}// GitHub sync update
