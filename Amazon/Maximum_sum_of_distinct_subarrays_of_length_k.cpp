# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0, maxi = 0;
        int n = nums.size();

        unordered_map<int, int> m;

        for (int i = 0; i < k; i++) {
            sum += nums[i];
            m[nums[i]]++;
        }

        int i = 0, j = k - 1;

        while (j < n) {
            if (m.size() == k)
                maxi = max(maxi, sum);

            sum -= nums[i];

            m[nums[i]]--;
            if (m[nums[i]] == 0)
                m.erase(nums[i]);

            i++;
            j++;

            if (j < n) {
                sum += nums[j];
                m[nums[j]]++;
            }
        }
        return maxi;
    }
};