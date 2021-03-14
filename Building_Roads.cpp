#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
V<V<int>>roads;
V<int>vis;
int n;
V<V<int>>ans;
void bfs(int x){
	queue<int>q;
	q.push(x);
	vis[x]=1;
	
	while(!q.empty()){
		int size=q.size();
		int y;
		for(int i=0;i<size;i++){
			y=q.front();
			q.pop();
			for(int i:roads[y]){
				if(!vis[i]){
					q.push(i);
					vis[i]=1;
				}
			}
		}
		if(q.size()==0){
			for(int i=1;i<=n;i++){
				if(!vis[i]){
					q.push(i);
					vis[i]=1;
					ans.push_back({i,y});
					break;
				}
			}
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
	}


}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int m;
	cin>>n>>m;
	roads.resize(n+1);
	vis.resize(n+1,0);
	int xx,yy;
	V<int>parent(n,INT_MAX);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		roads[x].push_back(y);
		roads[y].push_back(x);
		xx=x;yy=y;
	}
	for(int i=1;i<=n;i++){
		if(roads[i].size()==0){
			ans.push_back({xx,i});
			roads[i].push_back(xx);
			roads[xx].push_back(i);
		}
	}
	bfs(xx);

	


}