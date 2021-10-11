#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

bool check(int arr[],int i){
    if(i==0){
        return true;
    }
    if(arr[i]>=arr[i-1]){
        return check(arr,i-1);
    }else 
        return false;

}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    int arr[]={1,2,3,4,5,6};
    if(check(arr,5)) cout<<"sorted";
    else cout<<"not sorted";
    return 0;
}