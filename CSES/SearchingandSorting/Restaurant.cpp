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
   int n;
    cin>>n;
    vector<pair<int,bool>> v;
    int x; int y;
    while(n--){
    	cin>>x;cin>>y;
    	v.push_back(make_pair(x,true));
    	v.push_back(make_pair(y,false));
    }
   	sort(v.begin(),v.end());
   	int ans =0; int maxx =0;
   	for(int i=0;i<v.size();i++){
   		if(v[i].second==true){
   			ans++;
   			maxx = max(ans,maxx);
   		}else{
   			ans--;
   		}
   	}
   	cout<<maxx<<endl;
   return 0;
}