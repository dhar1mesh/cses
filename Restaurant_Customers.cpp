#include<bits/stdc++.h>
using namespace std; 

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	long long n;
	cin>>n;
	vector<pair<long long ,bool>>A;
	for(int i=0;i<n;i++){
		long long x,y;
		cin>>x>>y;
		A.push_back({x,true});
		A.push_back({y,false});
	}

	sort(A.begin(),A.end());
	long long ans=0,mxx=0;
	for(int i=0;i<A.size();i++){
		if(A[i].second){
			mxx++;
			ans=max(mxx,ans);
		}
		else mxx--;
		// ans=max(ans,mxx);
	}
	cout<<ans<<"\n";
	
}