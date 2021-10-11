#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

string dig[]={"zero","one","two","three","four","five","six","seven","eight","nine"}; 

string solve_2048(int n){
    if(n==0) return "";
    string ans=solve_2048(n/10);
    ans=ans+dig[n%10]+" ";
    return ans;
}

int str_to_int(string s,int n){
    if(n==0) return 0;
    int ans=str_to_int(s,n-1);
    ans=ans*10 + s[n-1]-'0';
    return ans;
}

int no_of_binaryStrings(int n){
    if(n<0) return 0;
    if(n==0) return 1;
    if(n==1) return 2;
    return no_of_binaryStrings(n-1)+no_of_binaryStrings(n-2);
}

void all_Subsets(string s,int n,string temp,int i){
    if(i== n){
        cout<<temp<<"\n";
    }else{
        all_Subsets(s,n,temp,i+1);
        temp+=s[i];
        all_Subsets(s,n,temp,i+1);
    }
}


void generate_acode(string in,string out,int n,int i){
    if(i==n){
        cout<<out<<"\n";
        return ;
    }
    int dig=in[i]-'0';
    char ch=dig+('A'-1);
    out.push_back(ch);
    generate_acode(in,out,n,i+1);
    out.pop_back();
    if(i+1 < n){
        int seconddig=in[i+1]-'0';
        int no = dig*10 + seconddig;
        char ch2 = no+('A'-1);
        if(no<26){
            out.push_back(ch2);
            generate_acode(in,out,n,i+2);
            out.pop_back();
        }
    }

}

void all_permutations(char *in,int i,set<string> &s){
    if(in[i]=='\0'){
        //cout<<in<<"\n";
        string t(in);
        s.insert(t);
        return;
    }
    for(int x=i;in[x]!='\0';x++){
        swap(in[x],in[i]);
        all_permutations(in,i+1,s);        
        swap(in[x],in[i]); //backtracking
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
    // cout<<solve_2048(2048)<<"\n";
    // cout<<str_to_int("0048",4)<<"\n";
    cout<<no_of_binaryStrings(4)<<"\n";
    // all_Subsets("abcd",4,"",0);
    // generate_acode("1234","",4,0);
    // char in[100]="aac";
    // char out[100];
    // set<string>s;
    // all_permutations(in,0,s);
    // for(string x:s) cout<<x<<"\n";
    return 0;
}