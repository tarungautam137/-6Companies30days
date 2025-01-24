# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid){
        
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> q;
        
        vis[row][col]=1;
        q.push({row,col});
        
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        while(!q.empty()){
            
            auto p=q.front();
            q.pop();
            
            int r=p.first,c=p.second;
            
            for(int i=0;i<4;i++){
                
                int nr=r+dr[i];
                int nc=c+dc[i];
                
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && vis[nr][nc]==0) {
                    
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int minDays(vector<vector<int>>& grid) {
        
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        int islands=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1 && vis[i][j]==0){
                    
                    islands++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        if(islands==0 || islands>1) return 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1){
                    
                    int isl=0;
                    grid[i][j]=0;
                    
                    for(int r=0;r<m;r++){
                        for(int c=0;c<n;c++){
                            
                            vis[r][c]=0;
                        }
                    }
                    
                    for(int r=0;r<m;r++){
                        for(int c=0;c<n;c++){
                            
                            if(vis[r][c]==0 && grid[r][c]==1){
                                
                                isl++;
                                bfs(r,c,vis,grid);
                            }
                        }
                    }
                    if(isl>1 ||isl==0) return 1;
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};