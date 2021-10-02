#include<bits/stdc++.h>
using namespace std;

int dp[1000]={INT_MAX};

vector<int>coins;

int mincoins_TD(int n){
	if(n==0) return 0;

	if(dp[n]) return dp[n];

	int ans=INT_MAX;
	for(int i=0;i<coins.size();i++){
		int coin=coins[i];
		if(n>=coin){
			ans=min(ans,mincoins_TD(n-coin)+1);
		}
	}
	return dp[n]=ans;
}


int mincoins_BU(int n){
	for(int i=0;i<coins.size();i++){
		
		for(int j=0;j<=n;j++){
			if(j==0) dp[j]=0;
			else if(coins[i]<=j){
				dp[j]=min(dp[j],dp[j-coins[i]]+1);
			} 
		}
	}
	return dp[n];
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
	coins.push_back(1);
	coins.push_back(7);
	coins.push_back(10);
	cout<<mincoins_TD(18)<<"\n";
	cout<<mincoins_TD(22)<<"\n";
	cout<<mincoins_BU(15)<<"\n";
	cout<<mincoins_BU(22)<<"\n";
}