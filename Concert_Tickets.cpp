#include<bits/stdc++.h>
using namespace std; 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n,m;
	cin>>n>>m;
	vector<long long >P(n),T(n);
	map<long long ,int>mp;
	for(int i=0;i<n;i++){
		long long x;
		cin>>x;
		mp[x]++;
	}
	for(int i=0;i<m;i++){
		cin>>T[i];
	}
	for(int i=0;i<m;i++){
		if(mp.size()==0){
			cout<<-1<<"\n";
			continue;
		}
		auto it=mp.upper_bound(T[i]);
		if(it==mp.begin()){
			cout<<-1<<"\n";
			continue;
		}
		// else if(it==mp.end()){
		// 	*(it)--;
		// 	if((*it).first)
		// 	cout<<-1<<"\n";
		// 	continue;
		// }
		else{
			*(it)--;
			cout<<(*it).first<<"\n";
			if(mp[(*it).first]==1){
				mp.erase((*it).first);
			}
			else{
				mp[(*it).first]--;
			}
		}

	}

}