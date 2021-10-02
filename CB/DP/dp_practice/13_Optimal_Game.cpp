#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

vector<int>arr(100,0);

int solve(int i,int j){
	if(i>j){
		return 0;
	}
	if(i==j) return arr[i];

	int op1= arr[i] + min(solve(i+2,j), solve(i+1,j-1));
	int op2= arr[j] + min(solve(i+1,j-1), solve(i,j-2));
	return max(op1,op2);
}

int Game_TD(int i,int j){
	if(i>j){
		return 0;
	}
	if(i==j) return arr[i];

	if(dp[i][j]) return dp[i][j];

	int op1= arr[i] + min(Game_TD(i+2,j), Game_TD(i+1,j-1));
	int op2= arr[j] + min(Game_TD(i+1,j-1), Game_TD(i,j-2));
	return dp[i][j]=max(op1,op2);
}

int Game_BU(){
	int n=arr.size();
	for(int k=1;k<n;k++){
		int i=0,j=k;
		
		while(j<n){
			int op1=arr[i]+min(dp[i+2][j],dp[i+1][j-1]);
			int op2=arr[j]+min(dp[i+1][j-1],dp[i][j-2]);
			dp[i][j]=max(op1,op2);
			i++,j++;
		}
	}
	return dp[0][n-1];
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
	for(int i=0;i<n;i++) cin>>arr[i];

	cout<<solve(0,n-1)<<"\n";
	cout<<Game_TD(0,n-1)<<"\n";
	cout<<Game_BU()<<"\n";
}