#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int li;
int mod = 1000000007;
int n = 0;
string s, ans = "";
map<string,int>m;
bool check[100];

void solve(string p){
    if(p.length()==n){
        if(m.find(p)==m.end()){
            m[p]++;
        }
    }else{
        for(int i=0;i<n;i++){
            if(check[i]) continue;
            check[i]=true;
            p.push_back(s[i]);
            solve(p);
            check[i]=false;
            p.pop_back();
        }
    }
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("input1.txt","r",stdin);
// 	freopen("output1.txt","w",stdout);
// #endif
   // string s;
    cin >> s;
    n=s.length();
    
    memset(check,0,sizeof(check));
    solve("");
    cout<<m.size()<<"\n";
    map<string,int> :: iterator itr;
    for(itr=m.begin();itr!=m.end();itr++){
        cout<<itr->first<<"\n";
    }
    return 0;
}

	