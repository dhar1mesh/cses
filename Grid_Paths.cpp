// #include<bits/stdc++.h>
// using namespace std; 
// #define ll long long
// #define V vector
// ll ans=0;
// V<V<ll>>dp;
// ll sol(vector<string>&g,int i,int j){
// 	if(i==g.size()-1&&j==g[0].size()-1&&g[i][j]=='.'){
		
// 		return 1;
// 	}
// 	if(g[i][j]!='.')return 0;
// 	if(dp[i][j]!=-1)return dp[i][j];
// 	if(i==g.size()-1){
// 		dp[i][j]=sol(g,i,j+1);
// 	}
// 	else if(j==g[0].size()-1){
// 		dp[i][j]=sol(g,i+1,j);
// 	}
// 	else {
// 		dp[i][j]=sol(g,i+1,j)+sol(g,i,j+1);
// 	}
// 	return dp[i][j];
	
	
// }
// int main(){
// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt","r",stdin);
// 	freopen("output.txt","w",stdout);
// 	#endif
// 	int n;
// 	cin>>n;
// 	dp.resize(n,V<ll>(n,-1));
// 	V<string>g;
// 	for(int i=0;i<n;i++){
// 		string x;
// 		cin>>x;
// 		g.push_back(x);
// 	}
// 	sol(g,0,0);
// 	cout<<ans<<"\n";
// }

#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
ll ans=0;
V<V<ll>>dp;
ll sol(vector<string>&g,int i,int j){
	if(i==g.size()-1&&j==g[0].size()-1&&g[i][j]=='.'){
		ans++;
		return 1;
	}
	if(dp[i][j]!=-1)return dp[i][j];
	if(g[i][j]!='.')return 0;

	g[i][j]='*';
	if(i==g.size()-1){
		
		dp[i][j]=sol(g,i,j+1);
		dp[i][j]%=1000000007;
		
	}
	else if(j==g[0].size()-1){
		
		dp[i][j]=sol(g,i+1,j);
		dp[i][j]%=1000000007;
	}
	
	else{

		dp[i][j]=sol(g,i+1,j)+sol(g,i,j+1);
		dp[i][j]%=1000000007;
		
	}
	g[i][j]='.';
	dp[i][j]%=1000000007;
	return dp[i][j];
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	V<string>g;
	dp.resize(n,V<ll>(n,-1));
	for(int i=0;i<n;i++){
		string x;
		cin>>x;
		g.push_back(x);
	}
	cout<<sol(g,0,0);
	// cout<<ans<<"\n";
	
}

