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

ll steps_TD(int n,int k){
    if(n==0) return 1;
    ll ans=0;

    if(dp[n]) return dp[n];
    for(int i=1;i<=k;i++){
        if(n>=i){
            ans=ans+steps_TD(n-i,k);
        }
    }
    dp[n]=ans;
    return ans;
}

ll steps_BU(int n,int k){
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i>=j) dp[i]+=dp[i-j];
        }
    }
    return dp[n];
}

ll steps_BU_optimized(int n,int k){
    dp[0]=dp[1]=1;
    ll sum=1;
    for(int i=2;i<=n;i++){
        // dp[i]=sum;
       
        if(i<=k){
            // sum+=dp[i];
            dp[i]= 2*dp[i-1];
        }else{
            // sum=sum+dp[i]-dp[i-k];
            dp[i]= 2*dp[i-1] - dp[i-k-1];
        }
        cout<<dp[i]<<" ";

    }
    return dp[n];
}

int main() {
	init_code();
    int n,k;
    cin>>n>>k;
    // cout<<steps_TD(4,3)<<"\n";
    cout<<steps_BU_optimized(6,3);
    return 0;
}