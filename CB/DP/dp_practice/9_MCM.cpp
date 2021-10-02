#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

vector<int>arr;

int solve(){
	int n=arr.size()-1;
	for(int i=1;i<n;i++){
		int r=0,c=i;
		while(c<n){
			int val=INT_MAX;
			for(int pivot=r;pivot<c;pivot++){
				val=min(val,dp[r][pivot]+dp[pivot+1][c]+ arr[r]*arr[pivot+1]*arr[c+1]);
			}
			dp[r][c]=val;
			r++,c++;

		}
	}
	return dp[0][n-1];
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