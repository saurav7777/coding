#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
int mod = 1000000007;


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("input1.txt","r",stdin);
// 	freopen("output1.txt","w",stdout);
// #endif
    int k;
    cin>>k;
    for (lli n = 1; n <= k; n++)
    {
        cout << n * n * (n * n - 1) / 2 - 4 * (n - 1) * (n - 2) << endl;
    }
    return 0;
}