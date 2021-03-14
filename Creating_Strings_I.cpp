#include<bits/stdc++.h>
using namespace std; 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	string s;
	int cnt=1;
	cin>>s;
	sort(s.begin(),s.end());
	
	vector<string>ans;
	ans.push_back(s);
	while(next_permutation(s.begin(),s.end())){
		ans.push_back(s);
		cnt++;
	}
	cout<<cnt<<"\n";
	for(string x:ans){
		cout<<x<<"\n";
	}
	
}