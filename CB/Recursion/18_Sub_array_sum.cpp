#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

vector<vector<int>>ans;
vector<int>temp;

bool compare(vector<int>a,vector<int>b){
    string x,y;
    for(int i=0;i<a.size();i++) x+=to_string(a[i]);

    for(int i=0;i<b.size();i++) y+=to_string(b[i]);
    return x<y;
}

void solve(int arr[],int n,int i,int sum,int t){
    if(i==n){
        if(sum==t){
            ans.push_back(temp);
        }
        return ;
    }
    solve(arr,n,i+1,sum,t);
    temp.push_back(arr[i]);
    solve(arr,n,i+1,(sum+arr[i]),t);
    temp.pop_back();
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int t;
    cin>>t;
    solve(arr,n,0,0,t);
    set<string>str;
    sort(ans.begin(),ans.end(),compare);
    for(int i=0;i<ans.size();i++){
        vector<int>v=ans[i];
        sort(v.begin(),v.end());
        string s="";
        for(int j=0;j<v.size();j++){
            s+=to_string(v[j]) + " ";
        }
        str.insert(s);     
    }
    for(string s:str){
        cout<<s<<"\n";
    }
    return 0;
}