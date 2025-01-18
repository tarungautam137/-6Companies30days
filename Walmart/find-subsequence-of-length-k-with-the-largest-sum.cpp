# include<bits/stdc++.h>
using namespace std;
bool comp(pair<int, int>& p1, pair<int, int>& p2) {

    if (p2.second > p1.second)
        return true;

    return false;
}
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        int i = 0, n = nums.size();

        while (pq.size() < k) {

            pq.push({nums[i], i});
            i++;
        }
        while (i < n) {

            auto p = pq.top();

            if (p.first < nums[i]) {
                pq.pop();
                pq.push({nums[i], i});
            }
            i++;
        }
        vector<pair<int, int>> v;

        while (!pq.empty()) {

            auto p = pq.top();
            pq.pop();

            v.push_back(p);
        }
        sort(v.begin(), v.end(), comp);

        vector<int> ans;
        for (auto it : v)
            ans.push_back(it.first);

        return ans;
    }
};