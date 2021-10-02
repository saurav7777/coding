#include<bits/stdc++.h>
using namespace std;

int dp[1001];

vector<int>arr(10000,1);
int n;

// int LIS_1(){
// 	dp[0]=1;
// 	int ans=INT_MIN;
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<i;j++){
// 			if(arr[j]<arr[i])
// 				dp[i]=max(dp[i],dp[j]+1);
// 			ans=max(ans,dp[i]);
// 		}
// 	}
// 	for(int i=0;i<=n;i++) cout<<dp[i]<<" ";
// 	return ans;
// }

int LIS_2(){

	for(int i=0;i<=n;i++) dp[i]=INT_MAX;
	dp[0]=INT_MIN;

	for(int i=0;i<n;i++){
		for(int i=0;i<=n;i++) cout<<dp[i]<<" ";
		cout<<"\n";
		for(int j=0;j<n;j++){
			if(arr[i]>dp[j] && arr[i]<dp[j+1]){
				dp[j+1]=arr[i];
			}
		}
	}

	int ans=INT_MIN;
	for(int i=0;i<=n;i++){
		if(dp[i]!=INT_MAX) ans=i;
	}
	// for(int i=0;i<=n;i++) cout<<dp[i]<<" ";
	// cout<<"\n";
	return ans;
}

int LIS_2_Optimize(){

	for(int i=0;i<=n;i++) dp[i]=INT_MAX;
	dp[0]=INT_MIN;

	for(int i=0;i<n;i++){
		int length=upper_bound(dp,dp+n+1,arr[i])-dp;
		
		if(arr[i]>dp[length-1] && arr[i]<dp[length]){
				dp[length]=arr[i];
		}
	}

	int ans=INT_MIN;
	for(int i=0;i<=n;i++){
		if(dp[i]!=INT_MAX) ans=i;
	}
	for(int i=0;i<=n;i++) cout<<dp[i]<<" ";
	cout<<"\n";
	return ans;
}


int LIS_3(){
	
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	// cout<<LIS_1()<<"\n";
	cout<<LIS_2()<<"\n";
	// cout<<LIS_2_Optimize()<<"\n";
	
}