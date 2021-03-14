#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	map<long ,long>mp;
	long ans=0;
	long cnt=0;
	long pre=-1;
	for(int i=0;i<n;i++){
		long x;
		cin>>x;
		if(mp.find(x)!=mp.end()){
			pre=max(pre,mp[x]);
		}
		long y=i-pre;
		ans=max(ans,y);
		mp[x]=i;
		
	}
	cout<<ans<<"\n";
	
}