#include<bits/stdc++.h>
using namespace std; 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	long long n,x;
	cin>>n>>x;
	vector<pair<long long ,long long> >A;

	for(int i=0;i<n;i++){
		long long c,d;
		cin>>c;
		A.push_back({c,i});
	}
	sort(A.begin(),A.end());
	int i=0,j=n-1;
	while(i<j){
		// cout<<A[i].first+A[j].first<<"\n";
		if(A[i].first+A[j].first==x){
			cout<<A[i].second+1<<" "<<A[j].second+1<<"\n";
			return 0;
		}
		if(A[i].first+A[j].first>x)j--;
		else i++;
	}
	cout<<"IMPOSSIBLE\n";
	
}