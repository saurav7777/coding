#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;



int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int m;
        cin>>m;
        sort(arr,arr+n);
        int l=0,r=n-1;
        int x=0,y=0;
        while(l<r){
            if(arr[l]+arr[r] == m){
                x=arr[l];
                y=arr[r];
                l++;
                r--;
            }else if(arr[l]+arr[r] > m){
                r--;
            }else{
                l++;
            }
        }
        cout<<"Deepak should buy roses whose prices are "<<x<<" and "<<y<<".\n";
    }
    return 0;
}