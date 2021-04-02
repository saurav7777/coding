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
   int n,x;
   cin>>x>>n;
   vector<int>p(n,0);
   fr(0,n) cin>>p[i];

   set<int> d={x};
   unordered_map<int,int>mp;
   mp[x]=1;
   set<int> up={0,x};
   set<int> lo={-x,0};


   fr(0,n){
   		int y=p[i];
   		int a = *up.upper_bound(y);
        int b = -*lo.upper_bound(-y);
        up.insert(y); lo.insert(-y);
        mp[a-b]--;
        if (mp[a-b]==0){
            d.erase(a-b);
        }
        d.insert(a-y),d.insert(y-b);
        mp[a-y]++, mp[y-b]++;
        cout<<(*d.rbegin())<<" ";
   }
   return 0;
}