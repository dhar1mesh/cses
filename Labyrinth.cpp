#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
V<V<char>>g,pre;
V<V<int>>vis;
V<char>res;
pair<int,int>start,ed;
vector<char>dir={'L','R','U','D'};
vector<int>dirx={0,0,-1,1};
vector<int>diry={-1,1,0,0};
bool isvalid(pair<int,int>y){
	if(y.first>=g.size()||y.second>=g[0].size())return 0;
	return 1;
}
void sol(){
	queue<pair<int,int>>q;
	q.push(start);
	vector<vector<int>>vis(g.size(),vector<int>(g[0].size(),0));
	vis[start.first][start.second]=1;
	while(!q.empty()){
		pair<int,int>x=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			pair<int,int>y=make_pair(x.first+dirx[i],x.second+diry[i]);
			if(isvalid(y)&&!vis[y.first][y.second]&&g[y.first][y.second]!='#'){
				vis[y.first][y.second]=1;
				pre[y.first][y.second]=i;
				q.push(y);
			}
		}

	}
	if(vis[ed.first][ed.second]){
		string ans="";
		int cnt=0;
		
		while(ed!=start){
			int p=pre[ed.first][ed.second];
			ans+=dir[p];
			ed=make_pair(ed.first-dirx[p],ed.second-diry[p]);
			cnt++;
			
		}
		reverse(ans.begin(),ans.end());
		cout<<"YES\n"<<ans.size()<<"\n"<<ans;
		return ;
	}
	cout<<"NO\n";
	
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n,m;
	cin>>n>>m;
	g.resize(n,V<char>(m));
	pre.resize(n,V<char>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>g[i][j];
			if(g[i][j]=='A'){
				start.first=i;
				start.second=j;
			}
			if(g[i][j]=='B'){
				ed.first=i;
				ed.second=j;
			}
		}
	}
	sol();
}