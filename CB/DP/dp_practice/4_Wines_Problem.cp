#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

vector<int>wines;

int wines_BU(){
	int n=wines.size();
	for(int y=0;y<n;y++){
		int i=0,j=y;
		for(int k=y;k<n;k++,i++,j++){
			if(i==j){
				dp[i][j]=wines[i]*(n-y);
			}else{
				int op1=wines[i]*(n-y) + dp[i+1][j];
				int op2=wines[j]*(n-y) + dp[i][j-1];
				dp[i][j]=max(op1,op2);
			}
			// cout<<dp[i][j]<<" ";
		}
		// cout<<"\n";
	}
	return dp[0][n-1];
}

int wines_TD(int i,int j,int year){
	if(i>j){
		dp[i][j]=0;
		return 0;
	}
	if(dp[i][j]) return dp[i][j];
	int op1=wines[i]*year + wines_TD(i+1,j,year+1);
	int op2=wines[j]*year + wines_TD(i,j-1,year+1);
	return dp[i][j]=max(op1,op2);
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
	wines.push_back(2);
	wines.push_back(3);
	wines.push_back(5);
	// wines.push_back(1);
	// wines.push_back(4);
	cout<<wines_TD(0,wines.size()-1,1)<<"\n";
	cout<<wines_BU()<<" ";
}