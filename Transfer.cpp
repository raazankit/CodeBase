#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<long long, long long>> st;
    for (int i = 0; i < n; i++) {
        long long curr_sum = a[i];
        long long curr_cnt = 1;

        while (!st.empty()) {
            long long prev_sum = st.back().first;
            long long prev_cnt = st.back().second;
            
            long long max_prev = prev_sum / prev_cnt;
            if (prev_sum % prev_cnt != 0 && prev_sum > 0) max_prev++;
            
            long long min_curr = curr_sum / curr_cnt;
            if (curr_sum % curr_cnt != 0 && curr_sum < 0) min_curr--;

            if (max_prev > min_curr) {
                curr_sum += prev_sum;
                curr_cnt += prev_cnt;
                st.pop_back();
            } else {
                break;
            }
        }
        st.push_back({curr_sum, curr_cnt});
    }

    vector<long long> a_prime(n);
    int idx = 0;
    for (auto& p : st) {
        long long s = p.first;
        long long c = p.second;
        
        long long val = s / c;
        if (s % c != 0 && s < 0) val--;
        
        long long rem = s - val * c;
        for (long long i = 0; i < c - rem; i++) {
            a_prime[idx++] = val;
        }
        for (long long i = 0; i < rem; i++) {
            a_prime[idx++] = val + 1;
        }
    }

    long long ans = 0;
    long long curr_p = 0;
    long long curr_p_prime = 0;
    for (int i = 0; i < n; i++) {
        curr_p += a[i];
        curr_p_prime += a_prime[i];
        ans += (curr_p - curr_p_prime);
    }

    cout << ans << "\n";
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