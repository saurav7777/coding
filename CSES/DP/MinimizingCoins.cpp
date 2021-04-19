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

int dp[1000001];
int ans=INT_MAX;

int solve(int arr[],int n,int sum){
    if(x==0){
       return dp[x]=0;
    }

    if(dp[sum]) return dp[sum];

    if()
}


int main() {
    // init_code();
    int n,x;
    cin>>n>>x;
    int arr[n];
    fr(0,n) cin>>arr[i];
    dp[0]=0;
    fr(1,x+1) dp[i]=INT_MAX;
   	for(int i=0;i<n;i++){
      for(int j=0;j<=x;j++){
          if(j>=arr[i]){
              if(dp[j-arr[i]]!=INT_MAX)
                  dp[j]=min(dp[j],dp[j-arr[i]]+1);
          }
          // cout<<dp[j]<<" ";
      }
      // cout<<"\n";
    }
    if(dp[x]==INT_MAX) ans=-1;
    else ans=dp[x];
   	cout<<ans;
    return 0;
}