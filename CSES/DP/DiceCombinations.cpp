#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
using namespace std;
 
void init_code(){
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif 
}

ll dp[1000001];

ll solve(ll n){
	if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]) return dp[n];

    ll ans=0;
    for(int j=1;j<=6;j++){
		ans=(ans+solve(n-j))%mod;
	}
	ans=ans%mod;
	return dp[n]=ans;
}

int main() {
    // init_code();
    ll n;
    cin>>n;
   	solve(n);
   	// dp[0]=0;
   	// dp[1]=1;
   	// for(int i=2;i<=n;i++){
   	// 	for(int j=1;j<=6;j++){
   	// 		if(j<=i) dp[i]=(dp[i]%mod + dp[i-j]%mod)%mod;
   	// 		else{
   	// 			dp[i]=dp[i-1];
   	// 		}
   	// 	}
   	// 	cout<<dp[i]<<" ";
   	// }
   	cout<<dp[n]%mod;
    return 0;
}