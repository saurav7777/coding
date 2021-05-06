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
 
ll dp[1000],arr[1000];


int main() {
	init_code();
    int n;
    cin>>n;
    fr(0,n) cin>>arr[i];
    // dp[0]=arr[0]>0?arr[0]:0;
    // int ans=dp[0];
    // for(int i=1;i<n;i++){
    // 	dp[i]=arr[i]+dp[i-1];
    // 	if(dp[i]<0) dp[i]=0;
    // 	ans=max(ans,dp[i]);
    // }

    int ans=0,currsum=0;
    for(int i=0;i<n;i++){
    	currsum+=arr[i];
    	if(currsum<0) currsum=0;

    	ans=max(ans,currsum);
    }

    cout<<ans;
    return 0;
}