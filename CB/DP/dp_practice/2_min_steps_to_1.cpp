#include<bits/stdc++.h>
using namespace std;

int dp[1000]={0};
int par[1000]={0};
int minsteps(int n){
	if(n==1) return 0;
	if(dp[n]) return dp[n];

	int x,y,z;
	x=y=z=INT_MAX;
	if(n%2 == 0){
		x=minsteps(n/2)+1;
	}
	if(n%3 == 0){
		y=minsteps(n/3)+1;
	}
	z=minsteps(n-1)+1;
	int ans=min(x,min(y,z));
	return dp[n]=min(x,min(y,z));
}


int minsteps_BU(int n){
	int ans=0;

	dp[0]=0;
	dp[1]=0;
	for(int i=2;i<=n;i++){
		int x,y,z;
		x=y=z=INT_MAX;
		if(i%2==0) x=dp[i/2];
		if(i%3==0) y=dp[i/3];
		z=dp[i-1];
		ans=min(x,min(y,z));
		if(ans== x) par[i]=i/2;
		else if(ans==y) par[i]=i/3;
		else par[i]=i-1;

		dp[i]=min(x,min(y,z))+1;
	}
	int temp=n;
	while(temp!=1){
		cout<<par[temp]<<" ";
		temp=par[temp];
	}
	cout<<"\n";
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
	cout<<minsteps(10)<<"\n";
	cout<<minsteps(100)<<"\n";
	cout<<minsteps_BU(10)<<"\n";
	cout<<minsteps_BU(100)<<"\n";
}