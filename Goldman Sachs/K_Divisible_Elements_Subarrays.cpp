# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {

        map<vector<int>, int> mp;

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {

                int count = 0;
                vector<int> temp;

                for (int ind = i; ind <= j; ind++) {

                    if (nums[ind] % p == 0) count++;

                    temp.push_back(nums[ind]);
                }

                if (count <= k)  mp[temp]++;
            }
        }
        return mp.size();
    }
};