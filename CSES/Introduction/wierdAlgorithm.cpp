#include<bits/stdc++.h>
using namespace std;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("input1.txt","r",stdin);
// 	freopen("output1.txt","w",stdout);
// #endif
	long long int n;
	cin>>n;
	while(n!=1){
		cout<<n<<" ";
		if(n&1){
			n= 3*n +1;
		}else{
			n=n>>1;
		}
	}
	cout<<n<<" ";
	
}