# include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        int n=nums.size(),ind=n/2,sum=0;

        for(int x:nums){
            sum+=abs(x-nums[ind]);
        }
        return sum;
    }
};