# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // LONGEST COMMON SUBSTRING
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int m=nums1.size(),n=nums2.size(),maxi=0;

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                if(nums1[i]==nums2[j]){

                    dp[i+1][j+1]=1+dp[i][j];
                }
                else dp[i+1][j+1]=0;

                maxi=max(maxi,dp[i+1][j+1]);
            }
        }

        return maxi;
    }
};