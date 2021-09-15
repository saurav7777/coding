#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

int search_firstOcurence(int arr[],int start,int end,int key){
    int mid=(start+end)/2;
    int e=0;
    if(start==end) return end;
    if(arr[mid]==key){
        return search_firstOcurence(arr,start,mid-1,key);
    }else if(arr[mid]<key){
        return search_firstOcurence(arr,mid+1,end,key);
    }else{
        return search_firstOcurence(arr,start,mid-1,key);
    }
}

int search_rotated(int arr[],int n,int key){
    int l=0,r=n-1,ans=-1,mid=-1;
    while(l<=r){
        mid=(l+r)/2;
        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]>=arr[l]){
            if(key<=arr[mid] && key>=arr[l]){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }else{
            if(key>=arr[mid] && key<=arr[r]){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
    }
    return mid;
}

int search_LastOcurence(int arr[],int start,int end,int key){
    int mid=(start+end)/2;
    int e=0;
    if(start==end) return end;
    if(arr[mid]==key){
        return search_LastOcurence(arr,mid,end,key);
    }else if(arr[mid]<key){
        return search_LastOcurence(arr,mid+1,end,key);
    }else{
        return search_LastOcurence(arr,start,mid-1,key);
    }
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
    // int index=search_firstOcurence(arr,0,n-1,4);
    // int index2=search_LastOcurence(arr,0,n-1,4);
    // cout<<index<<" "<<index2<<"\n";

    int ind=search_rotated(arr,n,4);
    cout<<ind<<" ";
    return 0;
}