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
ll arr[101];

ll coins_TD(int i,ll n,ll x){
	// cout<<arr[i]<<" "<<x<<" ";
	// cout<<dp[x]<<" ";
	if(x==0) return 0;
	if(x<0 || i>=n) return INT_MAX;

	// if(dp[x]) return dp[x];
	// ll ans=INT_MAX;
	// for(int i=0;i<n;i++){
	// 	if(arr[i]<=x){
	// 		ll sub_prob= coins_TD(i,n,x-arr[i]);
	// 		ans=min(sub_prob+1,ans);
	// 	}

	// }
	// dp[x]=ans;

	if(dp[x]!=0) return dp[x];
 
	ll op1,op2;
	op1=op2=INT_MAX;
 
	if(x>=arr[i]) op1=1+coins_TD(i,n,x-arr[i]);
 
	op2=coins_TD(i+1,n,x);
 
	dp[x]=min(op1,op2);
	
	return dp[x];
}

ll minsteps_BU(ll n){
	// fr(1,x+1) dp[i]=INT_MAX;
 //   	for(int i=0;i<n;i++){
 //      for(int j=0;j<=x;j++){
 //          if(j>=arr[i]){
 //              if(dp[j-arr[i]]!=INT_MAX)
 //                  dp[j]=min(dp[j],dp[j-arr[i]]+1);
 //          }
 //          // cout<<dp[j]<<" ";
 //      }
 //      // cout<<"\n";
 //    }
	return 0;
}

int main() {
	init_code();
    ll n,x;
    cin>>n>>x;
    fr(0,n) cin>>arr[i];
    // fr(0,x+1) dp[i]=INT_MAX;
    dp[0]=0;
    // cout<<n;
    sort(arr,arr+n)
    coins_TD(0,n,x);
    if(dp[x]==INT_MAX) cout<<"-1";
    else cout<<dp[x];

    return 0;
}