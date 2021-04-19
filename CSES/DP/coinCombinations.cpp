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
// int ans=INT_MAX;

int solve(int arr[],int n,int sum,int j){
   if(sum==0) return 1;
   if(j>=n) return 0;
   if(sum<0) return 0;
   if(dp[sum]) return dp[sum];

   ll ans=0;
   // for(int i=0;i<n;i++){
   //  if(sum>=arr[i])
   //    ans= (ans%mod + solve(arr,n,sum-arr[i],j)%mod)%mod;
   //    // ans= (ans%mod + solve(arr,n,sum,j+1)%mod)%mod;
   // }

   ans= (solve(arr,n,sum-arr[j],j)%mod + solve(arr,n,sum,j+1)%mod)%mod;
    // ans= (ans%mod + solve(arr,n,sum,j+1)%mod)%mod;
   return dp[sum]=ans;
}


int main() {
    init_code();
   
    int n;
    cin>>n;
    int sum;
    cin>>sum;
    int* arr=new int[n+1];
    for(int i=0;i<n;i++){cin>>arr[i];}
    // int dp[1000001]={0};
    dp[0]=1;

  //for non distinct ways
    // for(int i=1;i<=sum;i++){
    //     for(int j=0;j<n;j++){
    //         if(i-arr[j]>=0){
    //             dp[i]+=(dp[i-arr[j]])%mod;
    //         }
    //     }

    // }


  // for distinct ways
    // for(int i=0;i<n;i++){
    //     for(int j=1;j<=sum;j++){
    //         if(j-arr[i]>=0){
    //             dp[j]+=(dp[j-arr[i]])%mod;
    //         }
    //     }

    // }
      solve(arr,n,sum,0);
    cout<<(dp[sum])%mod<<endl;

    return 0;
}