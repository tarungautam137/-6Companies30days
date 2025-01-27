# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        unordered_map<int,int> m;

        int i=0,j=0,len=0,n=nums.size();

        while(j<n){

            m[nums[j]]++;

            if(m[nums[j]]>k){

                len=max(len,j-i);

                while(!(m[nums[j]]<=k)){

                    m[nums[i]]--;
                    i++;
                }
            }
            if(j==n-1){

                len=max(len,j-i+1);
                return len;
            }
            
            j++;
        }
        return len;
    }
};