#include<bits/stdc++.h>
using namespace std; 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	string s;
	cin>>s;
	unordered_map<int,int>mp;
	for(char c:s){
		mp[c]++;
	}
	int cnt=0;
	// char x='';
	string xx="";
	int x=-1;
	for(auto it:mp){
		if(it.second&1){
			cnt++;
			x=it.first;
		}
		
		
		if(cnt==2){
			cout<<"NO SOLUTION\n";
			return 0;
		}
		for(int i=0;i<it.second/2;i++){
			xx+=it.first;
		}
	}
	

	if(x!=-1){
		s=xx;
		s+=x;
		reverse(xx.begin(),xx.end());
		s+=xx;
		cout<<s<<"\n";
	}
	else {
		s=xx;
		reverse(xx.begin(),xx.end());
		s+=xx;
		cout<<s<<"\n";
	}


	
}