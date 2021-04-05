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
ll k;

bool solve(vector<ll>arr,int n,ll time){
	unsigned long long  count=0;
	for(int i=0;i<n;i++){
		count += time/arr[i];
		
	}
  // cout<<time<<"->"<<count<<"\n";
	if(count<k) return false;
	return true;
} 

int main() {

   // init_code();
   int n;
   cin>>n>>k;
   vector<ll>arr(n,0);
   ll l=1,r=0,mid=0,ans=0;
   for(ll i=0;i<n;i++){
   		cin>>arr[i];
  
   } 
   r=1e18;
   sort(arr.begin(),arr.end());
   while(l<=r){
   		mid=(l+r)/2;
   		// cout<<mid<<"->";
   		if(solve(arr,n,mid)){
   			ans=mid;
   			r=mid-1;
   		}else{
   			l=mid+1;
   		}
   }

  cout<<ans;
	
   return 0;
}