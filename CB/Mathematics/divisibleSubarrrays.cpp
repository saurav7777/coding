#include<bits/stdc++.h>
using namespace std;
#define ll long long

int subarraysDivByK(vector<int>& A, int K) {
        map<int,int>m;
        int ans=0,sum=0;
        m[0]=1;
        for(int i=0;i<A.size();i++){
            // if(A[i]==0){
            //     m[0]++;
            // }
            sum=(sum+A[i]);
            int temp=(sum%K +K)%K;
            m[temp]++;
        }
        
        map<int,int>::iterator it;
        for(it=m.begin();it!=m.end();it++){
            
            int m=it->second;
            ans+=m*(m-1)/2;
        }
        // if(m[0]==1){
        //     ans++;
        // }
        return ans;
    }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
	
	return 0;
}