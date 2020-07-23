#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int li;
int mod = 1000000007;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("input1.txt","r",stdin);
// 	freopen("output1.txt","w",stdout);
// #endif
   long long int t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << ((a + b) % 3 == 0 && (min(a, b) * 2 >= max(a, b)) ? "YES" : "NO") << endl;
    }
    return 0;
}

	