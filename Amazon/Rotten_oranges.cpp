# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m=grid.size(),n=grid[0].size(),t=0;

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
            }
        }

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!q.empty()){

           pair<pair<int,int>,int> p=q.front(); 
           q.pop();

           int tm=p.second;
           int row=p.first.first;
           int col=p.first.second;

           t=max(t,tm);

           for(int k=0;k<4;k++){

            int nrow=row+drow[k];
            int ncol=col+dcol[k];
            
            if(nrow<m&&nrow>=0&&ncol<n&&ncol>=0&&vis[nrow][ncol]==0&&grid[nrow][ncol]==1){
                vis[nrow][ncol]=2;
                q.push({{nrow,ncol},tm+1});
            }
           }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0&&grid[i][j]==1)
                return -1;
            }
        }
        return t;
    }
};