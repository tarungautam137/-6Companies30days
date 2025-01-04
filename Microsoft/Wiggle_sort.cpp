# include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int j = n - 1, i = (n - 1) / 2;
        vector<int> v;
        while (i >= 0) {
            v.push_back(nums[i]);
            if (j > (n - 1) / 2)
                v.push_back(nums[j]);
            i--;
            j--;
        }
        nums = v;
    }
};