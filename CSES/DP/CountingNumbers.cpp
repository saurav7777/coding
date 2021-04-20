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

map<ll,int>mp;
ll ans;

void solve(ll a,ll b,ll num){
	 if(num>b) return;
   if(mp.find(num)!=mp.end()) return;
   if(num>=a && num<=b) ans++;

   for(int i=0;i<=9;i++){
      if(i != (num%10)){
          ll temp= num*10 + i; 
          solve(a,b,temp);
      }
   }
  
}


int main() {
    init_code();
   
    
    ll a,b;
    cin>>a>>b;
    for(int i=1;i<=9;i++)
      solve(a,b,i);
    
    if(a==0) ans++;
    cout<<ans;

    return 0;
}