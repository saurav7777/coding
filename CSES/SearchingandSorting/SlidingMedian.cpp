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

int n,k,med;
multiset<ll>up;
multiset<ll,greater<ll>>lr; 

void init_code(){
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif 
}

void rebalance() {	
        if (lr.size() < up.size()) {
            lr.insert(*up.begin());
            up.erase(up.begin()); 
        }
        
        if (lr.size() > up.size() + 1) {
            up.insert(*lr.begin()); 
            lr.erase(lr.begin());
        }
    }


void add(int x){
	lr.insert(x); 
    up.insert(*lr.begin()); 
    lr.erase(lr.begin());
	rebalance();
	// cout<<med<<" ";
}


void del(int x){
	// int sl=lr.size(),su=up.size();
	if(lr.find(x)!=lr.end()){
		lr.erase(lr.find(x));		
	}else{
		up.erase(up.find(x));
	}
	rebalance();
}



int main() {
    // init_code();
    
    cin>>n>>k;
    vector<ll>arr(n,0);
    fr(0,n) cin>>arr[i];
   

    int i=0,j=0;
  
    for(int j=0;j<n;j++){
    	
    	int num=arr[j];
    	add(num);

    	if(j < k-1) continue;

    	if(j>=k){
    		del(arr[j-k]);
    	}
    	if (k % 2) {
            cout<<*lr.begin()<<" ";
        } else {
            cout<<min(*lr.begin(),*up.begin())<<" ";
        }
    	
    }
    return 0;
}