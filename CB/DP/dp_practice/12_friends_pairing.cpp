#include<bits/stdc++.h>
using namespace std;

int dp[1000];

int solve(int n){
	if(n<=1) return 1;
	// if(n<=0) return 0;

	if(dp[n]) return dp[n];
	dp[n] = solve(n-1) + (n-1)*(solve(n-2));
	// cout<<ans<<" ";
	return dp[n];
}

int countFriendsPairings(int n) 
{ 
  
    // Filling dp[] in bottom-up manner using 
    // recursive formula explained above. 
    for (int i = 0; i <= n; i++) { 
        if (i <= 2) 
            dp[i] = i; 
        else
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2]; 
    } 
  
    return dp[n]; 
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
	cout<<solve(3)<<"\n";
	cout<<solve(4)<<"\n";
	cout<<solve(5)<<"\n";

	cout<<countFriendsPairings(3)<<"\n";
	cout<<countFriendsPairings(4)<<"\n";
	cout<<countFriendsPairings(5)<<"\n";
}