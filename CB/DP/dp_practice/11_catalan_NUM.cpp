#include<bits/stdc++.h>
using namespace std;

int dp[1000];

void catalan(int n){
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i]+=(dp[j-1]*dp[i-j]);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<dp[i]<<" ";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
	catalan(10);
}