# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int subset,vector<vector<int>>& dist,int n){

        int nodes=0,edges=0,md=0;

        for(int i=0;i<n;i++){

            if((subset>>i)&1){

                nodes++;

                for(int j=i+1;j<n;j++){

                    if((subset>>j)&1) {

                        md=max(md,dist[i][j]);
                        if(dist[i][j]==1) edges++;
                    }
                }
            }
        }
        if(nodes==edges+1)
        return md;

        return 0;
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> dist(n,vector<int>(n,100));

        for(auto& edge:edges){

            dist[edge[0]-1][edge[1]-1]=1;
            dist[edge[1]-1][edge[0]-1]=1;

            dist[edge[0]-1][edge[0]-1]=0;
            dist[edge[1]-1][edge[1]-1]=0;
        }

        for(int k=0;k<n;k++){

            for(int i=0;i<n;i++){

                for(int j=0;j<n;j++){

                    dist[i][j]=min(dist[i][j],(dist[i][k]+dist[k][j]));
                }
            }
        }
        vector<int> ans(n-1,0);

        for(int i=1;i<(1<<n);i++){

            int md=f(i,dist,n);

            if(md>0) ans[md-1]++;
        }
        return ans;
    }
};