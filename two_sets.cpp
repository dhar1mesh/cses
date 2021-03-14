#include<bits/stdc++.h>
using namespace std; 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	long n;
	cin>>n;
	
	long long sum=(n*(n+1))/2;
	
	
	if(n==1||sum&1){
		cout<<"NO\n";
		return 0;
	}
	sum/=2;
	unordered_map<int,int>mp;
	long long res=sum;
	int cnt=0;
	for(int i=n;i>=n/2;i--){
		res-=i;
		mp[i]=1;
		cnt++;
		if(res==0)break;
		if(res<i){
			mp[res]=1;
			cnt++;
			break;
		}
	}
	cout<<"YES\n";
	cout<<cnt<<"\n";
	for(auto it:mp){
		cout<<it.first<<" ";
	}
	cout<<"\n";
	cout<<n-cnt<<"\n";
	for(int i=1;i<=n;i++){
		if(mp.find(i)==mp.end())cout<<i<<" ";
	}
	
}