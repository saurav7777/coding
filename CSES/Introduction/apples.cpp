#include <bits/stdc++.h>

#define lli long long int
#define li long int
#define ld long double
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//  freopen("input1.txt","r",stdin);
//  freopen("output1.txt","w",stdout);
// #endif
    lli n;
    cin >> n;
    lli arr[n];
    lli total =0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        total+=arr[i];
    }
    sort(arr,arr+n);
    total=total;
    lli x=0,y=0;
    total /= 2LL;
    for(int i=n-1;i>=0;i--){
        if (total - arr[i] >= 0)
        {
           x+=arr[i];
            total -= arr[i];
        }
        else
        {
            y+=arr[i];
        }
    }
    if(x>y){
        cout<<(x-y)<<"\n";
    } else{
        cout<<(y-x)<<"\n";
    }
    
    return 0;
}