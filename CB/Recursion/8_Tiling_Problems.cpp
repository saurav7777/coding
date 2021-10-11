#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

int fib[1000007]={0};

ll solve_recursive(ll n,ll m){
    if(n<=m-1ll){
        fib[n]=1ll;
        return 1ll;
    }
    if(fib[n]) return fib[n]%mod;
    fib[n]=(solve(n-1ll,m)%mod + solve(n-m,m)%mod)%mod;
    return fib[n]%mod;
}

int solve(int n,int m){
    for(ll i=1;i<=n;i++){
        if(i<m) fib[i]=1;
        else if(i==m) fib[i]=2;
        else{
            fib[i]=(fib[i-1]%mod + fib[i-m]%mod)%mod;
        }
    }
    return fib[n];
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;

        cout<<solve(n,m)<<"\n";
    }
    return 0;
}