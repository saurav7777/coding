#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("input1.txt","r",stdin);
// 	freopen("output1.txt","w",stdout);
// #endif
	int n;
	cin>>n;
	int temp=n;
	if(n>1 && n<4) {
		cout<<"NO SOLUTION";
		return 0;
	}else if(n==4){
		cout<<"2 4 1 3";
		return 0;
	}
	while(temp>0){
		cout<<temp<<" ";
		temp=temp-2;
	}
	temp=n-1;
	while(temp>0){
		cout<<temp<<" ";
		temp=temp-2;
	}
}