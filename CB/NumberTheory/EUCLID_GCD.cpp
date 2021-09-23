#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

ll x,y,g;

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

void extgcd(ll a,ll b){
    if(b==0){
        x=1;
        y=0;
        g=a;
        return ;
    }
    extgcd(b,a%b);
    //cout<<x<<" "<<y<<"\n";
    ll x1=y;
    ll y1=x - (a/b)*y;
    x=x1;
    y=y1;
}

void modInv(ll n){
    extgcd(n,mod);
    x=(x%mod +mod)%mod;
    cout<<x<<"\n";
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    //gcd(30,24);
    // cout<<gcd(30,24)<<" ";
    // //gcd(30,60);
    // cout<<gcd(30,60)<<" ";
    // cout<<"\n";
    // extgcd(30,24);
    // cout<<g<<" ";
    // extgcd(30,60);
    // cout<<g<<" ";
    modInv(3);
    return 0;
}