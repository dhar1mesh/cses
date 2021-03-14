#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
#define mod 1000000007
#define map map<long long,long long>
int n,m;
V<V<ll>>planets;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m;
	planets.resize(31,V<ll>(n+1));
	for(int i=0;i<n;i++){
		cin>>planets[0][i];
		planets[0][i]--;
	}
	for(int i=1;i<30;i++){
		for(int j=0;j<n;j++){
			planets[i][j]=planets[i-1][planets[i-1][j]];
		}
	}
	while(m--){
		ll a,b;
		cin>>a>>b;
		a--;
		b--;
		int cnt=0;
		V<ll>vis(n+1,0);
		int cntt=0;
		for(int i=0;i<30;i++){
			
			cnt++;
			if(a==b){
				cout<<cnt<<"\n";
				break;
			}
			cntt++;
			// if(cntt>1000){
			// 	cout<<"exit";
			// 	exit(0);
			// }
			vis[a]=1;
			// cout<<cnt<<" "<<a<<"\n";
			// a=planets[i][a];
			if(vis[planets[i][a]]){
				cout<<-1<<endl;
				break;
			}
			vis[planets[i][a]]=1;


		}
	}
}