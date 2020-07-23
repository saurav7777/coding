#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int li;
int mod = 1000000007;

li solve(li x){
    li y=5;
    li ans=0;
    while(x>=y){
        ans+=(x/y);
        y=y*5;
    }
    return ans;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("input1.txt","r",stdin);
// 	freopen("output1.txt","w",stdout);
// #endif
    li tc;
    cin >> tc;
    cout<<solve(tc)<<"\n";
   
    return 0;
}