/*
The coding blocks members went to the success party of their first ever online boot-camp at Murthal. They ordered P number of paranthas. The stall has L cooks and each cook has a rank R. A cook with a rank R can cook 1 parantha in the first R minutes 1 more parantha in the next 2R minutes, 1 more parantha in 3R minutes and so on(he can only cook a complete parantha) ( For example if a cook is ranked 2.. he will cook one parantha in 2 minutes one more parantha in the next 4 mins and one more in the next 6 minutes hence in total 12 minutes he cooks 3 paranthas. In 13 minutes also he can cook only 3 paranthas as he does not have enough time for the 4th parantha). Calculate the minimum time needed to cook all the paranthas.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

ll check(ll a[],ll n,ll mid,ll p){
    ll count=1,sum=0,i=0;
    for(int i=0;i<=n;i++){
        sum+=a[i];
        if(sum>mid){
            count++;
            sum=a[i];
        }
    }
    return count;
}

ll solve(ll arr[],ll s,ll n,ll p){
    ll mid=0,l=INT_MIN,r=0,ans=0;
    for(int i=0;i<=n;i++) r+=arr[i];
    for(int i=0;i<=n;i++) l=max(l,arr[i]);

    while(l<r){
        mid=(l+r)/2;
        int chk=check(arr,n,mid,p);
       
       if(chk<=p){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    return l;
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif

    ll p,l;
    cin>>p;
    cin>>l;
    ll arr[l];
    for(int i=0;i<l;i++) cin>>arr[i];
    ll ans=solve(arr,0,l-1,p);
    cout<<ans<<"\n";
    return 0;
}