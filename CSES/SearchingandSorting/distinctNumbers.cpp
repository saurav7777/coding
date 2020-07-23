#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second 
#define PB push_back 
#define MP make_pair

typedef unsigned long long int li;
typedef vector<int> vi; 
typedef pair<int,int> pi;

int mod = 1000000007;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("input1.txt","r",stdin);
// 	freopen("output1.txt","w",stdout);
// #endif
    
   li n;
   cin>>n;
   map<li,li>m;
   for(int i=0;i<n;i++){
        int num;
        cin>>num;
        m[num]++;
   }
    cout<<m.size()<<"\n";
    return 0;
}