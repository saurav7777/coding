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
 

bool comp(pair<int,bool>a,pair<int,bool>b){
    if(a.first==b.first) {
      if(a.second==true) return false;
      if(b.second==false) return true;
      return true;
    }
    else return a.first<b.first;
}

int main() {
    init_code();
    ll T=1;
    //cin>>T;
    while(T--){
       vector<pair<ll,ll>> v;
       ll n,k;
       cin>>n>>k;
       for(ll i=0;i<n;i++){
          ll a,c;
          cin>>a>>c;
          // pushing end time, start time
          v.push_back({c,a});
       }
       sort(v.begin(),v.end());
       multiset<ll,greater<ll>>st;

       // for(auto x:v) cout<<x.second<<"->"<<x.first<<"\n";
       // ll curr=v[0].first;
       ll ans=0;
       for(ll i=0;i<n;i++){

           ll arr=v[i].second;
            // ll largest_dep = *st.begin();
            auto largest_dep = st.lower_bound(arr);

            if(largest_dep!=st.end() && (arr>= *largest_dep)){
                // cout<<"erase->"<<*largest_dep<<" "<<arr<<"\n";
                st.erase(largest_dep);
                st.insert(v[i].first);
                ans++;
            }else {
                if((st.size()<k)){
                  st.insert(v[i].first);
                  ans++;
               }
            }

           // if(st.size()<k){
           //    st.insert(v[i].first);
           //    ans++;
           // }else{
           //    ll arr=v[i].second;
           //    // ll largest_dep = *st.begin();
           //    auto largest_dep = st.lower_bound(arr);

           //    if(largest_dep!=st.end() && (arr>= *largest_dep)){
           //        cout<<"erase->"<<*largest_dep<<" "<<arr<<"\n";
           //        st.erase(largest_dep);
           //        st.insert(v[i].first);
           //        ans++;
           //    }
           // }
           // cout<<*st.begin()<<" ";
       }
       cout<<ans<<"\n";
    }
   return 0;
}