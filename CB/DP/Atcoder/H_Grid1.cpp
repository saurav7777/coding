#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll mod=1000000007;

ll dp[1001][1001];
ll mat[1001][1001];
ll h,w;

ll solve(){
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(mat[i][j]==0) dp[i][j]=0;
			else if(i==1 && j==1){
				dp[i][j]=1;
			}else if(i==1){
				dp[i][j]=dp[i][j-1];
			}else if(j==1){
				dp[i][j]=dp[i-1][j];
			}else{
				dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod;
			}
		}
	}

	// for(int i=1;i<=h;i++){
	// 	for(int j=1;j<=w;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	return dp[h][w]%mod;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);
#endif
	
	
	cin>>h>>w;

	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			char ch;
			cin>>ch;
			if(ch=='.'){
				mat[i][j]=1;
			}else mat[i][j]=0;
		}
	}
	cout<<solve()<<"\n";
}









