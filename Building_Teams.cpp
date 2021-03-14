#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
#define exit cnt++;if(cnt>=100000){ cout<<"exit";exit(0);}
int n,m;
int cnt=0;
V<V<int>>msg;
V<int>vis,ans;
int flg=0;
void bfs(int x){
	queue<int>q;
	q.push(x);
	ans[x]=1;
	while(!q.empty()){
		int size=q.size();
		while(size--){
			int x=q.front();
			q.pop();
			for(int y:msg[x]){
				if(!vis[y]){
					vis[y]=1;
					q.push(y);
					if(ans[x]==1){
						ans[y]=2;
					}
					else{
						ans[y]=1;
					}
				}
				else{
					// cout<<ans[x]<<" "<<ans[y]<<endl ;
					if(ans[y]==ans[x]){
						flg=1;
						cout<<"IMPOSSIBLE";
						return ;
					}
				}
			}
		}
		if(q.empty()){
		for(int i=1;i<ans.size();i++){
			if(ans[i]==0){
				q.push(i);
				ans[i]=2;
				break;
				}
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
	exit(0);
	msg.resize(n+1);
	int xx=-1;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		msg[x].push_back(y);
		msg[y].push_back(x);
		xx=x;
	}
	vis.resize(n+1,0);
	ans.resize(n+1,0);
	bfs(xx);
	if(!flg)
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
}