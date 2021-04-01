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
#define read(x) ll x; cin >> x
using namespace std;
 
void init_code(){
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif 
}
 
int main() {
   // init_code();
   read(n);
   read(x);
   vector<int>wt(n,0);
   fr(0,n) cin>>wt[i];
   ll ans=0,sum=0;
   sort(wt.begin(),wt.end());
   // fr(0,n)cout<<wt[i]<<" ";
   // cout<<"\n";
   int i=0,j=n-1;
   while(i<=j){
      // cout<<i<<"->"<<j<<"\n";
      if(i!=j && ((wt[i]+wt[j]) <= x)){
          // cout<<"hee\n";
          ans++;
          j--;
          i++;  
      }else{
        if(wt[j]<=x)
          ans++;
        j--;
      }
   }
   
   cout<<ans;
   return 0;
}