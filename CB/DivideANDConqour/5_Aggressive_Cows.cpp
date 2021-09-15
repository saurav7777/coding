#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

bool check(ll a[],ll n,ll c,ll dis){
    int i=1,count=1,last_pos=a[0];
    while(i<=n){
       
        if(a[i]-last_pos >=dis){
            count++;
            last_pos=a[i];
        }
        i++;
    }
    //cout<<"dis:"<<dis<<" count:"<<count<<"\n";
    return count>=c;
}

ll solve(ll arr[],ll s,ll e,ll c){
    ll l=1,r=0,mid=0;
    ll ans=INT_MAX;
    for(int i=0;i<=e;i++) r+=arr[i];
    //cout<<"r:"<<r<<"\n";
    while(l<=r){
        mid=(l+r)/2;
        if(check(arr,e,c,mid)){
            l=mid+1;
            //cout<<"mid:"<<mid<<"\n";
            ans=min(ans,mid);
        }else{
            r=mid-1;
        }
    }
    return ans;
}
int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    

    ll n,c;
    cin>>n>>c;
    cout<<n<<" "<<c<<"\n";
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    ll ans=solve(arr,0,n-1,c);
    cout<<ans<<"\n";
    return 0;
}