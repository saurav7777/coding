#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int mod=pow(10,9)+7;
int mod1=pow(10,9)+6;
int mx=1000005;
vector<int>prime(1000005,0);

void sieve(){
    prime[0]=1;
    prime[1]=1;
    for(int i=2;i<mx;i++){
        prime[i]=i;
    }
    for(int i=2;i*i<=mx;i++){
        if(prime[i]==i){
            for(int j=2*i;j<mx;j=j+i){
                if(prime[j]=j){
                    prime[j]=i;
                }
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
// #ifndef ONLINE_JUDGE
//  freopen("input1.txt","r",stdin);
//  freopen("output1.txt","w",stdout);
// #endif
   int t;
   cin>>t;
   sieve();
   while(t--){
        int n,ans=1;
        cin>>n;

        if(n==1){
            ans=1;
        }else{
            int smf=prime[n];
            int count=1;
            int j=n/smf;
            while(j!=1){
                if(prime[j]==smf){
                    count++;
                }else{
                    smf=prime[j];
                    ans=ans*(count+1);
                    count=1;
                }
                j=j/prime[j];
            }
            ans=ans*(count+1);
        }
        cout<<ans<<"\n";
   }
   
    return 0;
}

    