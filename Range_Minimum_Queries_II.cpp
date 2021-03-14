#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
#define mod 1000000007
#define map map<long long,long long>
int n,q;
V<ll>A,ST,mini;
ll mnm(int si,int qs,int qe,int start,int end){
	if(qe<start||qs>end)return INT_MAX;
	if(qs<=start&&qe>=end){
		// cout<<start<<" "<<end<<" 2nd\n";
		return mini[si];
	}
	else {
		int mid=start+(end-start)/2;
		// cout<<start<<" "<<end<<" 3rd\n";
		return min(mnm(2*si+1,qs,qe,start,mid),mnm(2*si+2,qs,qe,mid+1,end));
	}
}
ll buildtree(int si,int start,int end){
	if(start==end){
		ST[si]=A[start];
		mini[si]=ST[si];
		return ST[si];
	}
	int mid=start+(end-start)/2;
	mini[si]=min(buildtree(2*si+1,start,mid),buildtree(2*si+2,mid+1,end));
	// cout<<mini[si]<<" "<<A[start]<<" "<<A[end]<<" "<<start<<" "<<end<<"\n";
	return mini[si];
}
ll sumquery(int si,int qs,int qe,int start,int end){
	if(qs<=start&&qe>=end){
		// complete overlap
		return ST[si];
	}
	if(qe<start||qs>end)return 0;
	else {
		int mid=start+(end-start)/2;
		// partially overlap
		return sumquery(2*si+1,qs,qe,start,mid)+sumquery(2*si+2,qs,qe,mid+1,end);
	}
	
}
// void update(int si,int pos,ll val,int start,int end){
// 	if(start>pos&&end<pos)return ;
// 	if(start==end){
// 		mini[si]=val;
// 		return ;
// 	}
// 	int mid=start+(end-start)/2;
// 	update(2*si+1,pos,val,start,mid);
// 	update(2*si+2,pos,val,mid+1,end);
// 	mini[si]=min(mini[2*si+1],mini[2*si+2]);

// }
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        mini[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2+1, tl, tm, pos, new_val);
        else
            update(v*2+2, tm+1, tr, pos, new_val);
        mini[v] = min(mini[v*2+1]  ,mini[v*2+2]);
    }
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>q;
	
	V<ll>sum(n,0);
	for(int i=0,x;i<n;i++){
		cin>>x;
		A.push_back(x);
	}
	int k=log2(n)+2;
	k=1<<k;
	int m=n;
	ST.resize(k+1);
	mini.resize(k,INT_MAX);
	buildtree(0,0,m-1);
	while(q--){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==1){
			update(0,0,m-1,b-1,c);
		}
		else{
			cout<<mnm(0,b-1,c-1,0,m-1)<<" \n";
		}
	}

	
}