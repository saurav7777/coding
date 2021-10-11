#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

vector<int>temp;

int ans=0;
void solve(vector<vector<int>>wh,int i,int sum){
    if(i==wh.size()) return;
    int wh_dist=abs(wh[i][0]-wh[i][2])+abs(wh[i][1]-wh[i][3]);
    ans=min(ans,(sum-wh_dist+wh[i][4]));
    solve(wh,i+1,(sum-wh_dist+wh[i][4]));
    solve(wh,i+1,sum);   
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    int t,i=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int xs,ys,xe,ye;
        cin>>xs>>ys>>xe>>ye;
        vector<vector<int>>wh(n,vector<int>(5,0));
        for(int i=0;i<n;i++){
            cin>>wh[i][0]>>wh[i][1]>>wh[i][2]>>wh[i][3]>>wh[i][4];
        }
        int sum=abs(xe-xs)+abs(ye-ys);
        ans=sum;
        if(n>0) solve(wh,0,sum);
        
        cout<<"#"<<i<<" : "<<ans<<"\n";
        i++;
    }
    return 0;
}