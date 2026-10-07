#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> P(N);
    vector<int> pos(N);
    bool is_sorted = true;
    
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        pos[P[i]] = i;
        if (P[i] != i) is_sorted = false;
    }

    // 1. If already sorted, 0 operations needed
    if (is_sorted) {
        cout << 0 << "\n";
        return;
    }

    // 2. Find all "enclosed" elements
    vector<int> enclosed;
    int min_p = pos[0], max_p = pos[0];
    for (int m = 1; m < N; m++) {
        if (pos[m] > min_p && pos[m] < max_p) {
            enclosed.push_back(m);
        }
        min_p = min(min_p, pos[m]);
        max_p = max(max_p, pos[m]);
    }

    // 3. V-Shape arrays have no enclosed elements and are mathematically impossible to sort
    if (enclosed.empty()) {
        cout << -1 << "\n";
        return;
    }

    // 4. 1-Operation Win: Check if any enclosed element is ALREADY at its correct index
    int best_m = -1;
    for (int m : enclosed) {
        if (pos[m] == m) {
            best_m = m;
            break;
        }
    }

    if (best_m != -1) {
        cout << 1 << "\n";
        cout << N - 1 << "\n";
        for (int i = 0; i < N; i++) {
            if (i != best_m) cout << i << " ";
        }
        cout << "\n";
        for (int i = 0; i < N; i++) {
            if (i != best_m) cout << i << " ";
        }
        cout << "\n";
        return;
    }

    // 5. 2-Operation Strategy: Use the first enclosed element to build a bridge
    int m = enclosed[0];
    int k = pos[m];

    // Find a target m' for the 2nd operation that won't conflict with our setup
    int m_prime = -1;
    for (int i = 2; i <= N - 2; i++) {
        if (i == m || i == k) continue;
        int empty_gt = 0; 
        for (int j = i + 1; j < N; j++) {
            if (j != k) empty_gt++;
        }
        if (empty_gt >= 1) {
            m_prime = i;
            break;
        }
    }

    // Construct the intermediate state P_prime
    vector<int> P_prime(N, -1);
    P_prime[k] = m;
    P_prime[m_prime] = m_prime;
    
    int A_less = -1, A_greater = -1;
    for (int i = 0; i < m_prime; i++) {
        if (P_prime[i] == -1) { A_less = i; break; }
    }
    for (int i = m_prime + 1; i < N; i++) {
        if (P_prime[i] == -1) { A_greater = i; break; }
    }

    // Bracket m' with 0 and 1 to guarantee it becomes enclosed for operation 2
    P_prime[A_less] = 0;
    P_prime[A_greater] = 1;

    // Fill the rest of the empty spots with remaining available values
    vector<int> remaining_vals;
    for (int i = 0; i < N; i++) {
        if (i != m && i != m_prime && i != 0 && i != 1) {
            remaining_vals.push_back(i);
        }
    }
    
    int ptr = 0;
    for (int i = 0; i < N; i++) {
        if (P_prime[i] == -1) {
            P_prime[i] = remaining_vals[ptr++];
        }
    }

    // Output the 2 required operations
    cout << 2 << "\n";
    
    // --- Operation 1 ---
    cout << N - 1 << "\n";
    for (int i = 0; i < N; i++) {
        if (i != k) cout << i << " ";
    }
    cout << "\n";
    for (int i = 0; i < N; i++) {
        if (i != k) cout << P_prime[i] << " ";
    }
    cout << "\n";

    // --- Operation 2 ---
    cout << N - 1 << "\n";
    for (int i = 0; i < N; i++) {
        if (i != m_prime) cout << i << " ";
    }
    cout << "\n";
    for (int i = 0; i < N; i++) {
        if (i != m_prime) cout << i << " ";
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}