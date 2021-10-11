#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

int solve(int n){
    if(n<0) return 0;
    if(n==0) return 1;
    
    return solve(n-1)+ (n-1)*solve(n-2);
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    cout<<solve(1)<<" ";
    cout<<solve(2)<<" ";
    cout<<solve(3)<<" ";
    return 0;
}