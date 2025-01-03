# include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // FLOYD-WARSHALL!!!!
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> matrix(n,vector<int>(n,1e9));
        for(int i=0;i<edges.size();i++){
            matrix[edges[i][0]][edges[i][1]]=edges[i][2];
            matrix[edges[i][1]][edges[i][0]]=edges[i][2];
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                matrix[i][i]=0;
                for(int j=0;j<n;j++){
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        int city=-1,num=INT_MAX;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<=distanceThreshold) count++;
            }
            if(count<num) {
                city=i;
                num=count;
            }
            else if(count==num) city=i;
        }
        return city;
    }
};