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
 
int arr[100005],dp[100005];

void init_code(){
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif 
}
 
int main() {
    init_code();
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];

    dp[0]=0;
	// dp[1]=abs(arr[1]-arr[0]);
    for(int i=1;i<n;i++){
        int res=INT_MAX;
        for(int j=1;j<=k;j++){
            if(j>i) break;
            res = min(res,dp[i-j]+abs(arr[i]-arr[i-j]));
        }
        if(res!=INT_MAX)
            dp[i]=res;
    	
    }
    cout<<dp[n-1];
    return 0;
}