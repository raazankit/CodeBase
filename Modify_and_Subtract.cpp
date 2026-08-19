#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    vector<long long> d(N);
    d[0] = A[0];
    for(int i = 1; i < N; i++) {
        d[i] = A[i] - d[i-1];
    }
    
    vector<long long> S(N - 1);
    for(int i = 0; i < N - 1; i++) {
        long long sign = ((N - i) % 2 != 0) ? -1 : 1;
        S[i] = d[i] + sign * d[N - 1];
    }
    
    vector<bool> pref(N, false);
    bool ok = true;
    for(int i = 0; i < N; i++) {
        pref[i] = ok;
        if(d[i] < 0) ok = false; 
    }
    
    vector<bool> suff(N, false);
    ok = true;
    suff[N - 1] = true;
    for(int i = N - 2; i >= 0; i--) {
        if(S[i] < 0) ok = false;
        suff[i] = ok;
    }
    
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(pref[i] && suff[i]) {
            ans++;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    
    return 0;
}