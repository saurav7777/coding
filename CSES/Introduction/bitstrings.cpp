#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int li;
int mod = 1000000007;

int solve(li x){
    li a=2;
    li ans=1;
    while(x){
        if(x%2){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        x=x/2;
    }
    return ans%mod;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("input1.txt","r",stdin);
// 	freopen("output1.txt","w",stdout);
//#endif
    li tc;
    cin >> tc;
    cout<<solve(tc)<<"\n";
   
    return 0;
}