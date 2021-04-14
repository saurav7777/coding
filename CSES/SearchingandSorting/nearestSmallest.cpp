#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
using namespace std;
 
void init_code(){
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif 
}
 
int main() {
    // init_code();
   	ll n;
   	cin>>n;
   	vector<int>arr;
   	// unordered_map<int,int>mp;
   	// set<int,greater<int>>ans;
   	stack<int>st;
   	for(int i=0;i<n;i++){
   		int num;
   		cin>>num;
   		arr.push_back(num);
   		while(!st.empty() && num <= arr[st.top()]){
   				st.pop();
   		}

   		if(st.empty()) cout<<"0 ";
   		else{
   			cout<<st.top()+1<<" ";
   		}
   		st.push(i);
   		
   	}
    return 0;
}