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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif 
}
 
int main() {
   // init_code();
   int n,m,k;
   cin>>n>>m>>k;

   vector<int>app(n,0),apart(m,0);
   for(int i=0;i<n;i++) cin>>app[i];
   for(int i=0;i<m;i++) cin>>apart[i];

   sort(app.begin(),app.end());
   sort(apart.begin(),apart.end());

   int i=0,j=0;
   int ans=0;
   while(i<n && j<m){
   		if(abs(app[i]-apart[j])<=k){
   			ans++;
   			i++,j++;
   		}else if(app[i]>apart[j]){
   			j++;
   		}else i++;
   }
   cout<<ans<<"\n";
   return 0;
}