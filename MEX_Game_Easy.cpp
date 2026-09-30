#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<bool> present(N + 1, false);
    for (int i = 0; i < N; i++) {
        if (A[i] <= N) {
            present[A[i]] = true;
        }
    }
    
    long long M = 0;
    while (present[M]) {
        M++;
    }

    long long total_moves = 0;
    long long sum_less_than_m = 0;
    
    for (int i = 0; i < N; i++) {
        if (A[i] < M) {
            sum_less_than_m += A[i];
        } else if (A[i] > M) {
            total_moves += (A[i] - M - 1);
        }
    }
    
    long long reserved_sum = M * (M - 1) / 2;
    total_moves += (sum_less_than_m - reserved_sum);

    if (total_moves % 2 != 0) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

int main() {
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