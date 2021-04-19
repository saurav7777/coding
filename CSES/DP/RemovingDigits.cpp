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

   if(n==0) return 0;
   if(n<0) return 0;
   if(dp[n]) return dp[n];
   ll num=n,ans=INT_MAX;
    while(num){
        ll rem=num%10;
        ans=min(solve(n-rem),ans);
        num=num/10;
    }
	 return dp[n]=ans;
}

int main() {
    // init_code();
    ll n;
    cin>>n;
    dp[0]=0;
    fr(1,n+1) dp[i]=INT_MAX;
    for(int i=1;i<=n;i++){
        ll num=i;
        while(num){
            ll rem=num%10;
            dp[i]=min(dp[i],dp[i-rem]+1);
            num=num/10;
        }
    }
   	cout<<dp[n];
    return 0;
}