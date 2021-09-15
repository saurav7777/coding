/*
The coding blocks members went to the success party of their first ever online boot-camp at Murthal. They ordered P number of paranthas. The stall has L cooks and each cook has a rank R. A cook with a rank R can cook 1 parantha in the first R minutes 1 more parantha in the next 2R minutes, 1 more parantha in 3R minutes and so on(he can only cook a complete parantha) ( For example if a cook is ranked 2.. he will cook one parantha in 2 minutes one more parantha in the next 4 mins and one more in the next 6 minutes hence in total 12 minutes he cooks 3 paranthas. In 13 minutes also he can cook only 3 paranthas as he does not have enough time for the 4th parantha). Calculate the minimum time needed to cook all the paranthas.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

bool check(ll mid,ll n,ll m,ll x,ll y){
    ll total=m+(n-mid)*y;
   // cout<<total<<" "<<mid<<"\n";
    return (total)>= mid*x;
}

bool solve(string a,string b){
    if(a == b) return true;
    int al=a.length(),bl=b.length();
    if(al&1 || bl&1) return false;
    string a1=a.substr(0,(al/2));
    string a2=a.substr(al/2,al/2);
    string b1=b.substr(0,(bl/2));
    string b2=b.substr(bl/2,bl/2);
    return ((solve(a1,b1)&&solve(a2,b2))|| (solve(a1,b2)&&solve(a2,b1)));
}

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
        string a,b;
        cin>>a>>b;
        int n=a.length();
        bool ans=solve(a,b);
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}