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
 
ll n,k,sum;
vector<ll>arr;

bool check(ll mid){
	ll count=0,temp=0;
	fr(0,n){
		if(arr[i]>mid) return false;
		temp+=arr[i];
		if(temp>mid){
			count++;
			temp=arr[i];
		}
		if(count>=k) return false;
	}
	return true;
}

ll arrayDivision(ll start ,ll end){
	ll ans=0,mid=0;
	while(start<=end){
		mid=(start+end)/2;
		if(check(mid)){
			ans=mid;
			end=mid-1;
		}else{
			start=mid+1;
		}
	}
	return ans;
}

void init_code(){
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif 
}
 
int main() {
    // init_code();
   	
   	cin>>n>>k;
   	fr(0,n){
   		ll num;
   		cin>>num;
   		arr.push_back(num);
   		sum+=num;
   	}

   	cout<<arrayDivision(0,sum);
    return 0;
}