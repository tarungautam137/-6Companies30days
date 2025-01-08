#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    pair<string,int> f(int i,int j,vector<int>& arr,vector<vector<pair<string,int>>>& dp){
        
        if(i==j) {
            
            string s;
            s.push_back(char(i+65));
            
            return {s,0};
        }
        
        if(i==j-1) {
            
            string s;
            
            s.push_back('(');
            s.push_back(char(i+65));
            s.push_back(char(j+65));
            s.push_back(')');
            
            return {s,arr[i]*arr[j]*arr[j+1]};
        }
        if(dp[i][j].second!=-1) return dp[i][j];
        
        int mini=INT_MAX;
        string st;
        
        for(int k=i;k<=j-1;k++){
            
            auto p1=f(i,k,arr,dp);
            auto p2=f(k+1,j,arr,dp);
            
            int mult=arr[i]*arr[k+1]*arr[j+1]+p1.second+p2.second;
            
            if(mult<mini){

                mini=mult;
                st="("+p1.first+p2.first+")";
            }

        }
        return dp[i][j]={st,mini};
    }
    string matrixChainOrder(vector<int> &arr) {
        
         int n=arr.size();
        vector<vector<pair<string,int>>> dp(n,vector<pair<string,int>>(n,{"",-1}));
        
        auto mult=f(0,n-2,arr,dp);
        return mult.first;

    }
};