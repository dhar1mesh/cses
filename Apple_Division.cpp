#include<bits/stdc++.h>
using namespace std; 
unordered_map<int,unordered_map<long long ,int> >mp;
long long ans=INT_MAX;
void sol(vector<long long >A,long long sum,int i,long long cur,int cnt){
	
	ans=min(ans,abs(cur-sum));
	
	if(i>=A.size())return ;
	
	if(mp[i][cur]==1)return ;
	mp[i][cur]=1;
	sol(A,sum,i+1,cur,cnt);
	sol(A,sum-A[i],i+1,cur+A[i],cnt-1);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	vector<long long >A(n);
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>A[i];
		sum+=A[i];
	}
	sol(A,(sum),0,0,n/2);

	cout<<ans<<"\n";
	
}