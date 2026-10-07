#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Write your code for a single test case here
    int N,M;
    cin >> N >> M;
    string S;
    cin >> S;
    string L;
    cin >> L;
    int count_L =0;
    int count_R=0;
    int streak=1;
    int max_streak=0;
    for(int i = 0; i < N; i++){
       if(L.find(S[i]) != string::npos){
        streak=1;
            count_L++;
            count_R=0;
        
           max_streak = max(max_streak, max(count_L,count_R));
       }
       else{
            streak=0;
            count_R++;
            count_L=0;
           max_streak = max(max_streak, max(count_L,count_R));
       }
    }
    cout<<max_streak<<endl;
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
