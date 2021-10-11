#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

void BubbleSort(int a[],int i,int n){
    if(n==1){
        return;
    }
    // for(int i=0;i<n-1;i++){
    //     if(a[i+1]<a[i]){
    //         swap(a[i],a[i+1]);
    //     }
    // }

    //BubbleSortUtil(a,n-1);
    if(i==n-1){
        return BubbleSort(a,0,n-1);
    }
    if(a[i+1]<a[i]){
            swap(a[i],a[i+1]);
    }
    BubbleSort(a,i+1,n);
}

void merge(int a[],int l,int m,int r){
    int i,j,k;
    int nl=m-l+1;
    int nr=r-m;
    int L[nl],R[nr];

    for(i=0;i<nl;i++) L[i]=a[l+i];
    for(j=0;j<nr;j++) R[j]=a[m+1+j];

    i=0,j=0,k=l;
    while(i<nl && j<nr){
        if(L[i]<=R[j]) a[k++]=L[i++];
        else a[k++]=R[j++];
    }

    while(i<nl) a[k++]=L[i++];
    while(j<nr) a[k++]=R[j++];
}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m=(l+(r-l)/2);
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int partition(int a[],int l,int r){
    int pivot=a[r];
    int i=l-1;
    for(int j=l;j<=r;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void quickSort(int arr[],int l,int r){
    if(l<r){
        int p=partition(arr,l,r);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,r);
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
    int arr[]={4,3,3,9,5,9};
    int arr1[]={6,5,4,3,2,1};
    //BubbleSort(arr1,0,6);
    //mergeSort(arr1,0,5);
    quickSort(arr,0,5);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}