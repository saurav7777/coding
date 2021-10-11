#include<iostream>
using namespace std;

int solve(int arr[],int i,int j,int sum){
	if(i>j) return 0;
	if(i+1==j){
		return max(arr[i],arr[j]);
	}
	int t1=(sum-(solve(arr,i+1,j,sum-arr[i])));
	int t2=(sum-(solve(arr,i,j-1,sum-arr[j])));
	return max(t1,t2);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
	int n;
	cin>>n;
	int arr[n];
	int sum=0;
	for(int i=0;i<n;i++){
	 cin>>arr[i];
	 sum+=arr[i];
	}
	int ans=solve(arr,0,n-1,sum);
	cout<<ans;
	return 0;
}