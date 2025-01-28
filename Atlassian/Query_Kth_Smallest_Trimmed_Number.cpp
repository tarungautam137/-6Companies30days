# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // BRUTE FORCE
    vector<int> smallestTrimmedNumbers(vector<string>& nums,
                                       vector<vector<int>>& queries) {

        vector<int> ans;

        int n = nums[0].size(), m = nums.size();

        for (auto& q : queries) {

            int digits = q[1], k = q[0];

            priority_queue<pair<string, int>, vector<pair<string, int>>,
                           greater<pair<string, int>>>
                pq;

            for (int i = 0; i < m; i++) {

                string s = "";

                for (int j = n - digits; j < n; j++) {

                    s.push_back(nums[i][j]);
                }

                pq.push({s, i});
            }

            int count = 1;
            while (count < k) {

                pq.pop();
                count++;
            }

            ans.push_back(pq.top().second);
        }
        return ans;
    }
};