#include<bits/stdc++.h>
using namespace std;

int dp[101][11][101];

vector<int>arr(100,0);

int mod =1000003;

int n,x;

int solve(int i,int prev,int cnt){
	if(i==n) {
		if(cnt==x) return 1;
		return 0;
	}
	
	if(dp[i][prev][cnt]!=-1) return dp[i][prev][cnt];

	int ans=0;
	if(prev==1) ans= (ans%mod + solve(i+1,1,cnt+1)%mod)%mod;
	else ans=(ans%mod + solve(i+1,1,cnt)%mod)%mod;

	ans=(ans%mod + solve(i+1,0,cnt)%mod)%mod;
	return dp[i][prev][cnt]=ans;
}

int Diwali_TD(int i,int j){
	return 0;
}

int Game_BU(){
	
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif

	cin>>n>>x;
	for(int i=0;i<=100;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<=100;k++){
				dp[i][j][k]=-1;
			}
		}
	}
	cout<<n<<" "<<x<<"\n";
	cout<<solve(0,0,0)<<"\n";
}