#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
#define mod 1000000007
#define map map<long long,long long>
int n,m;
V<V<ll>>tele;
V<ll>ans,indegree;
queue<ll>q;
void bfs(){
	q.push(1);
	ans.resize(n+1,0);
	ans[1]=1;
	int cnt=0;
	for(int i=2;i<=n;i++){
		if(indegree[i]==0)q.push(i);
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(auto it:tele[x]){
			ans[it]=ans[x]+ans[it];
			ans[it]%=mod;
			indegree[it]--;
			if(indegree[it]==0){
				q.push(it);
			}
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m;
	tele.resize(n+1);
	indegree.resize(n+1,0);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		tele[x].push_back(y);
		indegree[y]++;
	}
	bfs();
	cout<<ans[n];
}