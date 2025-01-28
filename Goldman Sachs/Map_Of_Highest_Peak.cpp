# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int m=isWater.size(),n=isWater[0].size();

        vector<vector<int>> heights(m,vector<int>(n,-1));

        queue<pair<int,pair<int,int>>> q;

        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                if(isWater[i][j]==1){

                    heights[i][j]=0;

                    q.push({0,{i,j}});
                }
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!q.empty()){

            auto p=q.front();
            q.pop();

            int r=p.second.first,c=p.second.second,d=p.first;

            for(int i=0;i<4;i++){

                int nr=r+dr[i],nc=c+dc[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && heights[nr][nc]==-1){

                    heights[nr][nc]=d+1;
                    q.push({d+1,{nr,nc}});
                }
            }
        }
        return heights;
    }
};