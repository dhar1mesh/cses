#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
#define mod 1000000007
#define map map<long long,long long>
int n,q;
V<ll>A,ans;
void buildtree(int si,int start,int end){
	if(start==end){
		ans[si]=A[start];
		return ;
	}
	int mid=start+(end-start)/2;
	buildtree(2*si+1,start,mid);
	buildtree(2*si+2,mid+1,end);
}
void update(int si,int qs,int qe,int val,int start,int end){
	if(qe<start||qs>end)return ;
	if(qs<=start&&qe>=end){
 
		// cout<<start<<" "<<end<<" "<<ans[si]<<" "<<si<<" \n";
		ans[si]+=val;
		return ;
	}
	else{
		int mid=start+(end-start)/2;
		update(2*si+1,qs,qe,val,start,mid);
		update(2*si+2,qs,qe,val,mid+1,end);
	}
}
ll query(int si,int pos,int start,int end){
	// cout<<start<<" "<<end<<" "<<ans[si]<<" "<<si<<" \n";
	if(start==end){
		return ans[si];
	}
	int mid=start+(end-start)/2;
	// cout<<ans[si]<<"\n";
	
	if(mid<pos){
		return ans[si]+query(2*si+2,pos,mid+1,end);
	}
	else {
		return ans[si]+query(2*si+1,pos ,start,mid);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>q;
	A.resize(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	ans.resize(4*n+1,0);
	int m=n;
	buildtree(0,0,n-1);
	while(q--){
		int a;
		cin>>a;
		if(a==1){
			int b,c,d;
			cin>>b>>c>>d;
			b--,c--;
			// for(int i:ans)cout<<i<<" ";
			// cout<<"\n";
			update(0,b,c,d,0,n-1);
			// cout<<"\n";
			// for(int i:ans)cout<<i<<" ";
		}
		else{
			int k;
			cin>>k;
			ll x=query(0,k-1,0,m-1);
			// cout<<"\n"<<x<<"\n";
			cout<<x<<"\n";
		}
	}
}