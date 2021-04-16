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
   	vector<int>arr(n,0);
   	fr(0,n) {
   		cin>>arr[i];
   		// arr[i]=(arr[i]+n)%n;
   	}

   	map<int ,int>mp;
   	mp[0]=1;
   	ll sum=0,ans=0;
   	fr(0,n){
   		sum+=arr[i];
   		int temp=(sum%n +n)%n;
   		if(mp.find(temp)!=mp.end()) {
   			ans+=mp[temp];
   			// cout<<temp<<" "<<i<<"\n";
   		}
   		mp[temp]++;
   	}

   	cout<<ans;

    return 0;
}