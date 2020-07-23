#include<bits/stdc++.h>
using namespace std;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif
	long long int n,sum=0,tot=0;
	cin>>n;
	//cout<<n<<" ";
	tot=(n*(n+1))/2;
	n--;
	
	while(n--){
		int num;
		cin>>num;
		//cout<<num<<" ";
		sum+=num;
	}
	//cout<<sum;
	cout<<tot-sum<<" ";
	
}