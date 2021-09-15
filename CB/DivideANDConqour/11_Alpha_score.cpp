#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;
ll ans=0;

ll merge(ll arr[],ll s,ll mid,ll e){
    int i,j,k;
    //ll ans=0;
    int nl=mid-s+1;
    int nr=e-mid;
    ll L[nl],R[nr];

    for(i=0;i<nl;i++) L[i]=arr[i+s];
    for(i=0;i<nr;i++) R[i]=arr[i+mid+1];

    i=0,j=0,k=s;
    while(i<nl && j<nr){
        if(R[j]>L[i]){
            ans+=((L[i])*(nr-j));
            arr[k++]=L[i++];
        }else{
            arr[k++]=R[j++];
        }
    }

    while(i<nl) arr[k++]=L[i++];
    while(j<nr) arr[k++]=R[j++];
    return ans%mod;
}

ll solve(ll a[],ll s,ll e){
    if(s<e){
        ll mid=(s+e)/2;
        ll left=solve(a,s,mid)%mod;
        ll right=solve(a,mid+1,e)%mod;
        ll cross=merge(a,s,mid,e)%mod;
        return (cross)%mod;
    }
    return 0;
    
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    
    
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    solve(arr,0,n-1);
    cout<<ans<<"\n";
    
    return 0;
}