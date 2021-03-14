#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
vector<vector<ll>>dp;
int sol(string &s1,string &s2,int i,int j){
	if(i==s1.size()-1&&j==s2.size()-1)return s1[i]!=s2[j];
	if(i==s1.size())return s2.size()-j;
	if(j==s2.size())return s1.size()-i;
	ll &res=dp[i][j];
	if(res!=-1)return res;
	if(s1[i]==s2[j]){
		res=sol(s1,s2,i+1,j+1);
	}
	else{
		res=min(1+sol(s1,s2,i,j+1),
			min(1+sol(s1,s2,i+1,j),
				1+sol(s1,s2,i+1,j+1)));
	}
	return res;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	string s1,s2;
	cin>>s1>>s2;
	// cout<<s1<<" "<<s2;
	dp.resize(s1.size()+1,vector<ll>(s2.size()+1,-1));
	cout<<sol(s1,s2,0,0);
	
}