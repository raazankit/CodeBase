#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Write your code for a single test case here
    long long N;
    cin>>N;
    vector<long long> arr(N);
    long long total_sum=0;
    for(long long i=0;i<N;i++){
        cin>>arr[i];
        total_sum+=arr[i];
    }
    sort(arr.begin(),arr.end());
    long long curr_blue_sum=0;
    long long max_sum=-9e18;
    for(long long k=0;k<=N;k++){
        long long curr_red_sum=total_sum-curr_blue_sum;
        long long curr_b=k;
        long long curr_r=N-k;
        long long curr_diff=curr_r*curr_blue_sum+curr_b*curr_red_sum;
        max_sum=max(max_sum,curr_diff);
        if(k<N){
            curr_blue_sum+=arr[k];
        }
    }
    cout<<max_sum<<endl;

    
}

int main() {
    // Disables synchronization between C and C++ standard streams for maximum I/O speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long t = 1;
    // Read the number of test cases (Comment this out if the problem only has 1 test case)
    cin >> t; 
    
    while (t--) {
        solve();
    }
    
    return 0;
}// GitHub sync update
