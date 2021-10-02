#include<bits/stdc++.h>
using namespace std;

int dp[100]={0};

int fib_BU(int n){
	dp[0]=0,dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}

int fib_TD(int n){
	if(n==0||n==1){
		dp[n]=n;
		return dp[n];
	}
	if(dp[n]) return dp[n];
	dp[n]=fib_TD(n-1)+fib_TD(n-2);
	return dp[n];
}

int fib(int n){
	if(n==0 || n==1) return n;
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
	int n;
	cin>>n;
	cout<<fib_TD(n)<<"\n";

	cout<<fib_TD(5)<<"\n";

	cout<<fib_BU(6)<<"\n";

	cout<<fib_BU(7);
}