#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Write your code for a single test case here
    int dsa1,toc1,dm1;
    cin >> dsa1 >> toc1 >> dm1;
    int dsa2,toc2,dm2;
    cin >> dsa2 >> toc2 >> dm2;
    int total1 = dsa1 + toc1 + dm1;
    int total2 = dsa2 + toc2 + dm2;
    if(total1 > total2){
        cout << "DRAGON" << endl;
    } else if(total1==total2){
        if(dsa1 > dsa2){
            cout << "DRAGON" << endl;
        } else if(dsa1==dsa2){
            if(toc1 > toc2){
                cout << "DRAGON" << endl;
            } else if(toc1==toc2){
                if(dm1 > dm2){
                    cout << "DRAGON" << endl;
                } else if(dm1==dm2){
                    cout << "TIE" << endl;
                } else {
                    cout << "SLOTH" << endl;
                }
            } else {
                cout << "SLOTH" << endl;
            }
        } else {
            cout << "SLOTH" << endl;
        }
                
    }
    else {
        cout << "SLOTH" << endl;
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
}