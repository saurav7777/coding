#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

ll fib(ll n){
    if(n==0 || n==1){
        return 1;
    }
    return fib(n-1)+fib(n-2);
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    for(int i=1;i<10;i++){
        cout<<fib(i)<<" ";
    }
    return 0;
}