#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Write your code for a single test case here
    long long N;
    cin >> N;
    string A,B;
    cin >> A >> B;
    int count_A = count(A.begin(),A.end(),'1');
    int count_B = count(B.begin(),B.end(),'1');
    
        if(count_A%2!=count_B%2){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    
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
