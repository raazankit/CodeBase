#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Write your code for a single test case here
    int N,M,K;
    cin >> N >> M >> K;
    vector<int> A(N+1,0);
    int temp;
    for(int i=1;i<=M;i++){
        cin >>temp;
        A[temp] = 1;
    }
 
    for(int i=1;i<=N;i++){
        if(A[i]==0 && K>0){
            cout << i << " ";
            K--;
        }
    }
    cout << endl;

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
