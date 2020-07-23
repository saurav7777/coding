#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int mod=pow(10,9)+7;
int mod1=pow(10,9)+6;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
// #ifndef ONLINE_JUDGE
//  freopen("input1.txt","r",stdin);
//  freopen("output1.txt","w",stdout);
// #endif
    int n,mx=INT_MIN;
    cin>>n;
    vector<int>arr(n,0);

    for(int i=0;i<n;i++){
        cin>>arr[i];
        mx=max(arr[i],mx);
    }
    int count[mx+1]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    int c=0;
    bool flag=false;
    for(int i=mx;i>=1;i--){
        c=0;
        if(flag){
                break;
        }
        for(int j=i;j<=mx;j=j+i){
            
            if(count[j]>=2){
                cout<<j<<"\n";
                flag=true;
                break;
            }else if(count[j]==1){
                c++;
            }
            if(c==2){
                cout<<i<<"\n";
                flag=true;
                break;
            }
        }
    }
    return 0;
}

    