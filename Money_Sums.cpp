#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
vector<ll>ans;
V<V<ll>>dp;
V<ll>vis;
void sol(V<ll>&A,int i,int c){
	if(!vis[c]){
		vis[c]=1;
		ans.push_back(c);
	}
	if(i>=A.size())return;
	if(!vis[c]){
		vis[c]=1;
		ans.push_back(c);
	}
	if(dp[i][c]!=-1)return ;
	dp[i][c]=1;
	sol(A,i+1,c+A[i]);
	sol(A,i+1,c);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	V<ll>A(n);
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>A[i];
		sum+=A[i];
	}
	vis.resize(sum+1,0);
	dp.resize(n+1,V<ll>(sum+1,-1));
	vis[0]=1;
	sol(A,0,0);
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<"\n";
	for(ll c:ans)cout<<c<<" ";
}