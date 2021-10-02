#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

string s1,s2;
int n,m;
int LCS_TD(int i,int j){
	if(i==m || j==n ) return 0;

	if(s1[i]==s2[j]){
		return 1 + LCS_TD(i+1,j+1);
	}
	int op1=LCS_TD(i+1,j);
	int op2=LCS_TD(i,j+1);
	return max(op1,op2);
}

int LCS_BU(){
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0||j==0) dp[i][j]=0;
			else if(s1[i-1]==s2[j-1]) dp[i][j]=max(dp[i-1][j],max(dp[i-1][j-1],dp[i][j-1]))+1; 
			else dp[i][j]=max(dp[i-1][j],max(dp[i-1][j-1],dp[i][j-1])); 
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	return dp[m][n];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
	s1="abcd";
	s2="abedg";
	m=s1.length();
	n=s2.length();
	// cout<<LCS_TD(0,0)<<"\n";
	cout<<LCS_BU()<<"\n";

}