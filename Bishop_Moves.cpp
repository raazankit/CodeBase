#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Write your code for a single test case here
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    if((x1+y1) == (x2+y2)||(x1-y1) == (x2-y2)){
        cout<<1<<endl;
    }
    else if(((x1+y1)+(x2+y2)) % 2 == 0){
        cout<<2<<endl;
    }
    else{
        cout<<-1<<endl;
    }
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
