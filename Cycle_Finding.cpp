#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
V<V<ll>>g;
int n,m;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m;
	// g.resize(n+1);
	for(int i=0;i<m;i++){
		ll x,z,y;
		cin>>x>>y>>z;
		g.push_back({x,y,z});
	}
// cout<<"a";
	// exit(0);
	int x;
	vector<ll>ans(n+1,LLONG_MAX/2);
	ans[1]=0;
	int cnt=0;
	vector<ll>par(n+1);
	for(int i=1;i<=n;i++){
		x=-1;

		for(auto it:g){
			ll a=it[0];
			ll b=it[1];
			ll c=it[2];
			if(ans[a]+c<ans[b]){
				x=b;
				ans[b]=ans[a]+c;
				par[b]=a;
				// cout<<ans[a]+c<<" "<<ans[b]<<"\n";
			}
			
		}
	}
	// for(int i=1;i<=n;i++)cout<<ans[i]<<" \n";
	vector<ll>res;
    vector<ll> cycle;
	if(x==-1){
		cout<<"NO";
		return 0;
	}
	else{
        
		for(int i=1;i<=n;i++)x=par[x];
		//ll v=x;
		
        for (int v = x;; v = par[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
	}
	res.push_back(x);
	reverse(cycle.begin(),cycle.end());
	cout<<"YES\n";
	for(ll i:cycle){
		cout<<i<<" ";
	}
}