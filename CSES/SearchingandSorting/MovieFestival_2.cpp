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
   // init_code();
    int n,k;
    cin>>n>>k;
    int tt=k;
    vector<pair<int,bool>> v;
    int x; int y;
    while(n--){
    	cin>>x;cin>>y;
    	v.push_back(make_pair(x,true));
    	v.push_back(make_pair(y,false));
    }
   	sort(v.begin(),v.end(),comp);
   	int ans =0; int maxx =0;
   	for(int i=0;i<v.size();i++){
   		if(v[i].second==true){
   			if(k){
          ans++;
          k--;
        }
   			// maxx = max(ans,maxx);
   		}else{
   			//ans--;
        if(k<tt)
          k++;
   		}
   	}
   	cout<<ans<<endl;
   return 0;
}