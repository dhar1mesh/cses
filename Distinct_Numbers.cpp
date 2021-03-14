#include<bits/stdc++.h>
using namespace std; 
int main(){
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	map<long,long>mp;
	for(int i=0;i<n;i++){
		long x;
		cin>>x;
		mp[x]=1;
	}
	cout<<mp.size()<<"\n";
	
}