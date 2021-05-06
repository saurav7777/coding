#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
ll dp[100005][3];
ll a[100005];
ll b[100005];
ll c[100005];
ll n,k;
 

ll vacation(){
   
    dp[1][0]=a[1];
    dp[1][1]=b[1];
    dp[1][2]=c[1];
    for(int i=2;i<=n;i++){
    
        dp[i][0]=(a[i]+max(dp[i-1][1],dp[i-1][2]));
 
        dp[i][1]=(b[i]+max(dp[i-1][0],dp[i-1][2]));
        
        dp[i][2] = (c[i]+max(dp[i-1][1],dp[i-1][0]));
            
    }
 
    ll ans =max(dp[n][0],max(dp[n][1],dp[n][2]));
    return ans;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    
    cin>>n;
    ll arr[n+1];
    
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>b[i];
        cin>>c[i];
    }
    cout<<vacation()<<"\n";
}