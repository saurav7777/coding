#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

ll findMaxSubArray(ll a[],ll s,ll e){
    if(s>=e) return a[s];
    ll mid=(s+e)/2;
    ll left=findMaxSubArray(a,s,mid);
    ll right=findMaxSubArray(a,mid+1,e);
    ll leftsuffix=INT_MIN,rightPrefix=INT_MIN;
    ll sum=0;
    for(int i=mid;i>=s;i--){
        sum+=a[i];
        leftsuffix=max(leftsuffix,sum);
    }
    sum=0;
    for(int i=mid+1;i<=e;i++){
        sum+=a[i];
        rightPrefix=max(rightPrefix,sum);
    }
    return max(left,max(right,leftsuffix+rightPrefix));
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        ll ans=findMaxSubArray(arr,0,n-1);
        cout<<ans<<"\n";
    }
    return 0;
}