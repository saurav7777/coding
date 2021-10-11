#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;


int merge(int a[],int l,int m,int r){
    int i,j,k,cnt=0;
    int nl=m-l+1;
    int nr=r-m;
    int L[nl],R[nr];

    for(i=0;i<nl;i++) L[i]=a[l+i];
    for(j=0;j<nr;j++) R[j]=a[m+1+j];

    i=0,j=0,k=l;
    while(i<nl && j<nr){
        if(L[i]<=R[j]){ 
            a[k++]=L[i++];
        }else{
            a[k++]=R[j++];
            cnt+= (nl-i);
        }
    }

    while(i<nl) a[k++]=L[i++];
    while(j<nr) a[k++]=R[j++];

    return cnt;
}

int InversionCount(int arr[],int l,int r){
    if(l<r){
        int m=((l+r)/2);
        int x=InversionCount(arr,l,m);
        int y=InversionCount(arr,m+1,r);
        int z=merge(arr,l,m,r);
        return x+y+z;
    }
    return 0;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    int arr[]={2,4,3,5,1};
    // int arr1[]={6,5,4,3,2,1};
    // int t;
    // cin>>t;
    // while(t--){
    //     int n;
    //     cin>>n;
    //     int arr[n];
    //     for(int i=0;i<n;i++) cin>>arr[i];

    //     cout<<InversionCount(arr,0,n-1)<<"\n";
    //     // for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    //     // cout<<"\n";
    // }
    cout<<InversionCount(arr,0,4)<<" ";
    // cout<<InversionCount(arr1,0,5)<<" ";
   
    return 0;
}