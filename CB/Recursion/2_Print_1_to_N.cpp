#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

void write(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";  //dec order
    write(n-1);
    //cout<<n<<" "; //inc order
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    write(10);
    return 0;
}