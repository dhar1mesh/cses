#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
int n,m;
V<V<int>>road;
V<int>vis,ans;
int cntt=0;
int flg=0;
void sol(ll i,stack<ll>st){
	vis[i]=-1;
	st.push(i);
	for(auto it:road[i]){
		if(vis[it]==1)continue;
		if(!vis[it]){
			sol(it,st);
		}
		else if(vis[it]==-1){
			flg=1;
			vector<ll>ans;
			ans.push_back(it);
			while(!st.empty()){
				ans.push_back(st.top());
				if(it==st.top()){
					reverse(ans.begin(),ans.end());
					cout<<ans.size()<<"\n";
					for(auto j:ans)cout<<j<<" ";
					return ;
				}
				st.pop();
			}
			return ;
		}
		if(flg)return;
	}
	vis[i]=1;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>n>>m;
	road.resize(n+1);
	vis.resize(n+1,0);
	for(int i=0;i<m;i++){
		int x;
		int y;
		cin>>x>>y;
		road[x].push_back(y);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			stack<ll>st;
			sol(i,st);
			
			if(flg)return 0;
		}
	}
	cout<< "IMPOSSIBLE";
}