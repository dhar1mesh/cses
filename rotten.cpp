#include<bits/stdc++.h>
using namespace std;
int rot=0;
int fresh=0;
int tme=0;
void orangesRotting(vector<vector<int>>& grid) {
       vector<int> dir={-1,0,1,0,-1}; //used for finding all 4 adjacent coordinates
    
    int m=grid.size();
    int n=grid[0].size();
    
    queue<pair<int,int>> q;
    // int fresh=0; //To keep track of all fresh oranges left
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==2){
                rot++;
                q.push({i,j});
            }
            if(grid[i][j]==1)
                fresh++;
        }

    if(fresh==0){
        tme=0;
        fresh =0;

    }
    int ans=-1; //initialised to -1 since after each step we increment the time by 1 and initially all rotten oranges started at 0.
    while(!q.empty())
    {
        int sz=q.size();
        while(sz--)
        {
            pair<int,int> p=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int r=p.first+dir[i];
                int c=p.second+dir[i+1];
                if(r>=0 && r<m && c>=0 && c<n &&grid[r][c]==1)
                {
                    grid[r][c]=2;
                    rot++;
                    q.push({r,c});
                    fresh--; // decrement by 1 foreach fresh orange that now is rotten
                }
                
            }
        }
        ans++; //incremented after each minute passes
    }
    // if(fresh>0) return -1; //if fresh>0 that means there are fresh oranges left
    if(ans==-1) {
        
        tme=0;
        return ;
    } //we initialised with -1, so if there were no oranges it'd take 0 mins.
    tme=ans;

    
}

int main(){
    int n , m;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cin>>n>>m;
    vector<vector<int>>mat(n , vector<int>(m , 0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            int x;
            cin>>x;
            mat[i][j] = x;
        }
    }
    orangesRotting(mat);
    cout<<"time frames: "<<tme<<"\n"<<"fresh oranges: "<<fresh<<"\n"<<"Rotten oranges: "<<rot<<"\n";
}