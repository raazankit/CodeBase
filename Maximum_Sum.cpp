#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Write your code for a single test case here
    int N,K;
    cin>>N>>K;
    vector<int> arr(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int left=0,right=N-K-1;
    int sum=0;
while(right<N){
   int current_sum=0;
   for(int i=left;i<=right;i++){
       current_sum+=arr[i];
   }
   sum=max(sum,current_sum);
   left++;
   right++;
}
cout<<sum<<endl;
}

int main() {
    // Disables synchronization between C and C++ standard streams for maximum I/O speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // Read the number of test cases (Comment this out if the problem only has 1 test case)
    cin >> t; 
    
    while (t--) {
        solve();
    }
    
    return 0;
}// GitHub sync update
