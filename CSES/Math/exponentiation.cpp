#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int mod=pow(10,9)+7;
int mod1=pow(10,9)+6;

ll powermod(ll a,ll b){
    ll ans=1;
       
    while(b){
        if(b&1){
            ans=(ans*a)%mod1;
        }
        a=(a*a)%mod1;
        b=b>>1;
    }
    return ans%(mod1); 
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
// #ifndef ONLINE_JUDGE
//  freopen("input1.txt","r",stdin);
//  freopen("output1.txt","w",stdout);
// #endif
   int t;
   cin>>t;
   while(t--){
        ll a,b,c,ans=1;
        cin>>a>>b>>c;
        ll p=powermod(b,c);
        while(p){
            if(p&1){
                ans=(ans*a)%mod;
            }
            a=(a*a)%mod;
            p=p>>1;
        }
        cout<<ans%mod<<"\n";
   }
   
    return 0;
}

    