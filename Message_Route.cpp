#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
int n,m;
V<V<int>>msg;
void bfs(){
	queue<int>q;
	q.push(1);
	V<int>vis(n+1,0),par(n+1,-1);
	vis[1]=1;
	int cnt=0;
	while(!q.empty()){
		int size=q.size();
		while(size--){
			int x=q.front();
			q.pop();
			for(int i:msg[x]){
				if(!vis[i]){
					vis[i]=1;
					par[i]=x;
					q.push(i);

				}
			}
		}
	}
	if(vis[n]){
			V <int>ans;
			m=n;
			while(n!=1){
				n=par[n];
				ans.push_back(n);
			}
			reverse(ans.begin(),ans.end());
			cout<<ans.size()+1<<endl;
			for(int i:ans){
				cout<<i<<" ";
			}
			cout<<m<<"\n";
		}
		else{
			cout<<"IMPOSSIBLE";
		}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m;
	msg.resize(n+1);

	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		msg[x].push_back(y);
		msg[y].push_back(x);
	}

	bfs();


	
}