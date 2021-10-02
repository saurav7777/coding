#include<bits/stdc++.h>
using namespace std;

int dp[1000]={INT_MAX};

vector<int>arr;

int maxSubarray(){
	int max_so_far=INT_MIN,currsum=0;
	for(int i=0;i<arr.size();i++){
		currsum+=arr[i];
		if(max_so_far<currsum){
			max_so_far=currsum;
		}
	}
	return max_so_far;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
	
}