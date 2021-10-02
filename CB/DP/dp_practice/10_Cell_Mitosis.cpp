#include<bits/stdc++.h>
using namespace std;

int dp[1000];

int x,y,z;

int cell_Mitosis(int n){
	dp[0]=0;
	dp[1]=0;
	for(int i=2;i<=n;i++){
		if(i%2 == 0){
			dp[i]=min(dp[i/2]+x,dp[i-1]+y);
		}else{
			dp[i]=min(dp[i-1]+y,dp[(i+1)/2]+x+z);
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
	x=2,y=1,z=3;
	cout<<cell_Mitosis(5)<<"\n";
	cout<<cell_Mitosis(10)<<"\n";

}