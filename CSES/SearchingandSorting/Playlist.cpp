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
  int n;
	cin >> n;
	vector<int > v;
	map<int ,bool > mymap;
	int maxx=0;
	int currans=0;
	int j=0;
	for(int i=0;i<n;i++){
	    int k;
        cin>>k;
        v.push_back(k);
        if(mymap.find(k)==mymap.end()||mymap[k]==false){
                mymap[k]=true;
                currans++;
                maxx=max(currans,maxx);

        }
        else{
             while(v[j]!=k){
                    mymap[v[j]]=false;
                    j++;
             }
             //j++;
            // mymap[v[j]]=true;
             currans=(i-j);
             j++;


        }
	}
	cout<<maxx<<endl;
   return 0;
}