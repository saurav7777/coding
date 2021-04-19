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
ll price[1001];
ll pages[1001];
vector<pair<ll,ll>>arr;
// int ans=INT_MAX;

int solve(int n,int sum,int j){
	
   if(sum==0) return 0;
   if(j>=n) return 0;
   if(sum<0) return 0;
   if(dp[sum]) return dp[sum];

   ll ans1=0,ans2=0;
   

   if(sum>=price[j]){
   		ans1= pages[j] + (solve(n,sum-price[j],j+1) );
   		
   }
   ans2=   (solve(n,sum,j+1));
   
    // ans= (ans%mod + solve(arr,n,sum,j+1)%mod)%mod;
   // cout<<sum<<"->"<<price[j]<<" "<<max(ans1,ans2)<<"\n";
   return dp[sum]=max(ans1,ans2);
}


int main() {
    // init_code();
   
    int n;
    cin>>n;
    int sum;
    cin>>sum;
   
    for(int i=0;i<n;i++){cin>>price[i];}

    for(int i=0;i<n;i++){cin>>pages[i];}

  
    dp[0]=0;

	for(int i=0;i<n;i++){
		for(int j=sum;j>=price[i];j--){
			dp[j]=max(dp[j],dp[j-price[i]]+pages[i]);
			// cout<<dp[j]<<" ";
		}
		// cout<<"\n";
	}
 
    // solve(n,sum,0);
    cout<<(dp[sum])<<endl;

    return 0;
}