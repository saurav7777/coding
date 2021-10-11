#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

int solve(int w[],int c[],int n,int wt){
    if(n<0 || wt==0){
        return 0;
    }
    int m1=0,m2=0;
    if(w[n]<=wt){
        m1=c[n]+solve(w,c,n-1,wt-w[n]);
    }
    m2+=solve(w,c,n-1,wt);
    return max(m1,m2);
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    int w[]={ 10, 20, 30 };
    int c[]={ 60, 100, 120 }; 
    cout<<solve(w,c,2,50);
    return 0;
}