#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int X;
    cin>>X;
    int digit1 = X%10;
    X=X/10;
    int digit2 = X%10;
    if(digit1!=digit2){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}
