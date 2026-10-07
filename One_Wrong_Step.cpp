#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    cin >> N;
    

    string S;
    cin >> S;
    

    int U_count = count(S.begin(), S.end(), 'U');
    int D_count = count(S.begin(), S.end(), 'D');
    int L_count = count(S.begin(), S.end(), 'L');
    int R_count = count(S.begin(), S.end(), 'R');
    

    
    if ((abs(U_count - D_count) == 2 && L_count == R_count) || (abs(L_count - R_count) == 2 && U_count == D_count)){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        solve();
    }
    
    return 0;
}