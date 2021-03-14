#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
#define mod 1000000007
#define map map<long long,long long>
int n,m;
string target;
int sol(string s,int i,vector<string>str){
	if(s==target)return 1;
	if(s.size()>=target.size())return 0;
	int n=s.size();
	int size=str[i].size();
	// if(n+size<=m&&target.substr(n,n+size)==str[i]){
	// 	return 
	// 		sol(s+str[i],0,str)+
	// 		sol(s+str[i],i,str)+
	// 		sol(s,i+1,str);
	// }
	// else{
	// 	return sol(s,i+1,str);
	// }
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	string s;
	cin>>target;
	int n;
	cin>>n;
	cout<<n<<"\n";
	vector<string>str(n+1);
	for(int i=0;i<n;i++){
		cin>>str[i];
	}
	m=target.size();
	cout<<m<<"\n";
	cout<<target<<" ";
	cout<<sol("",0,str);
}