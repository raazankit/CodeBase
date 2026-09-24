#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<long long> a(n), p(n);
    int k = -1;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = a[i] + (i > 0 ? p[i - 1] : 0);
        if (p[i] < 0 && k == -1) {
            k = i;
        }
    }

    if (k == -1) {
        cout << "YES"<<endl;
        return;
    }

    vector<long long> min_suff(n);
    min_suff[n - 1] = p[n - 1];
    
    for (int i = n - 2; i >= 0; i--) {
        min_suff[i] = min(p[i], min_suff[i + 1]);
    }

    for (int j = 0; j <= k; j++) {
        if (a[j] <= min_suff[j]) {
            cout << "YES"<<endl;
            return;
        }
    }
    
    cout << "NO"<<endl;
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
}