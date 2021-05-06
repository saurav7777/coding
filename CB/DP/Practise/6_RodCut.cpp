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
 
ll dp[1000],price[1000];

ll rodcut_TD(ll n,int len){
	if(n==0) return 0;
	if(dp[n]) return dp[n];

	ll ans=INT_MIN;
	for(int i=1;i<=len;i++){
		ll sub_prob;
		if(n>=i){
			sub_prob= price[i]+rodcut_TD(n-i,len);
			ans=max(sub_prob,ans);
		}
	}
	dp[n]=ans;
	return dp[n];
}

ll rodcut_BU(ll n,int len){
	dp[0]=0;
	for(int i=1;i<=len;i++){
		for(int j=1;j<=n;j++){
			if(j>=i){
				dp[j]=max(dp[j],price[i]+dp[j-i]);
			}
			cout<<dp[j]<<" ";
		}
		cout<<"\n";
	}
	return dp[n];
}
int main() {
	init_code();
    ll n;
    cin>>n;
    int len;
    cin>>len;
    fr(1,len+1) cin>>price[i];

    // cout<<rodcut_TD(n,len)<<"\n";
    cout<<rodcut_BU(n,len);
    return 0;
}