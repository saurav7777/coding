#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

void solve(int n,int o,int c,string s){
    //cout<<o<<" "<<c<<"\n";
    if(o==n && c==n){
        cout<<s<<"\n";
    }
    if(c<o&&c<n){
        //c++;
        // string temp=s;
        // temp+=")";
        solve(n,o,c+1,s+")");
    }
    if(o<n){
        //o++;
        // string temp=s;
        // temp+="(";
        solve(n,o+1,c,s+"(");
    }
    
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    //solve(1);
    solve(3,0,0,"");
    //cout<<solve(3)<<" ";
    return 0;
}