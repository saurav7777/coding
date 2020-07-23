#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=pow(10,9)+7;
int mod1=pow(10,9)+6;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
 freopen("input1.txt","r",stdin);
 freopen("output1.txt","w",stdout);
#endif
    ll n,mx=INT_MIN,ans=0;
    cin>>n;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            ans=(ans+i)%mod;
            if(n/i != i){
                ans=(ans+n/i)%mod;
            }
        }
    }
    cout<<ans%mod<<"\n";
   
    return 0;
}

    