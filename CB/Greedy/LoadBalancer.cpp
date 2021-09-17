#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
	int arr[1000];
	int n;
	cin>>n;
	ll sum=0;
	for(int i=0;i<n;i++) {
		cin>>arr[i];
		sum+=arr[i];
	}

	ll avg=sum/n;
	if(avg*n != sum) {
		cout<<"NO Solution\n";
	}else{
		ll diff=0,max_load=0;
		for(int i=0;i<n;i++){
			diff+=(arr[i]-avg);
			max_load=max(max_load,abs(diff));
		}
		cout<<max_load<<"\n";
		
	}
	
	for(int j=1;j<n;j++){
		for(int k=1;k<n;k)
	}

}