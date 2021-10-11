#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

int firstOcc(int arr[],int n,int i,int key){
    if(n==0) return -1;
    if(i==n) return -1;
    if(arr[i]==key){
        return i;
    }
    return firstOcc(arr,n,i+1,key);
}

int firstOcc1(int arr[],int n,int key){
    if(n==0) return 1;
    if(a[0]==key) return 1;

    int i=firstOcc1(arr+1,n-1,key);
    if(i== -1) return -1;

    return i+1;
}


int lastOcc(int arr[],int n,int i,int key){
    if(n==0) return -1;
    if(i<0) return -1;
    //cout<<i<<" ";
    if(arr[i]==key){
        return i;
    }
    return lastOcc(arr,n,i-1,key);
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    int arr[]={1,6,5,6,6,5};
   
    cout<<firstOcc(arr,5,0,1)<<" ";
    cout<<"\n";
    cout<<lastOcc(arr,5,5,1);
    return 0;
}