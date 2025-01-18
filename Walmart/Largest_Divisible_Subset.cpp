#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // LONGEST DIVISIBLE SUBSEQUENCE
        // ONLY 1D DP ARRAY IS REQUIRED FOR TABULATION IN LIS.
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<int> len(n, 1), next;

        for (int i = 0; i < n; i++) {
            next.push_back(i);
        }
        int first = 0, maxi = 1;

        for (int i = n - 2; i >= 0; i--) {

            for (int j = n - 1; j > i; j--) {

                if (nums[j] % nums[i] == 0 && 1 + len[j] > len[i]) {

                    len[i] = 1 + len[j];
                    next[i] = j;
                }
            }
            if (len[i] > maxi) {
                maxi = len[i];
                first = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[first]);

        while (next[first] != first) {

            first = next[first];
            ans.push_back(nums[first]);
        }
        return ans;
    }
};