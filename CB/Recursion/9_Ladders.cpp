#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

int solveLadders(int n,int k){
    if(n<0) return 0;
    if(n==0) return 1;
    int ans=0;
    for(int i=1;i<=k;i++){
        ans+=solveLadders(n-i,k);
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
    cout<<solveLadders(1,3)<<" ";
    cout<<solveLadders(2,3)<<" ";
    cout<<solveLadders(4,3)<<" ";
    return 0;
}