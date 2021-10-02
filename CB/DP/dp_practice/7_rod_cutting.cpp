#include<bits/stdc++.h>
using namespace std;

int dp[1000]={0};

int prices[]={1,5,8,9,10,17,17,20};

int RodCutting_TD(int n){
	if(n<=0) return 0;

	int ans=INT_MIN;
	for(int i=0;i<n;i++){
		int cut=i+1;
		int curr_ans=prices[i]+RodCutting_TD(n-cut);
		ans=max(curr_ans,ans);
	}
	return dp[n]=ans;
}

int RodCutting_BU(int n){
	dp[0]=0;
	for(int len=1;len<=n;len++){
		int ans=INT_MIN;
		for(int i=0;i<len;i++){
			int cut=i+1;
			int curr_ans=prices[i]+dp[len-cut];
			ans=max(ans,curr_ans);
		}
		dp[len]=ans;
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
	cout<<RodCutting_TD(8)<<"\n";
	cout<<RodCutting_BU(8)<<"\n";
}