# include<bits/stdc++.h>
using namespace std;

// SORT ENVELOPES IN ASCENDING ORDER OF WIDTH AND DESCENDING ORDER OF HEIGHT AND THEN APPLY 
// LIS ON HEIGHTS ARRAY (FORGET ABOUT WIDTH) - DP(NLOGN)-BINARY SEARCH APPROACH.
bool comp(vector<int>& a, vector<int>& b) {

    if (a[0] != b[0])
        return b[0] > a[0];
    return a[1] > b[1];
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        int n = envelopes.size();

        sort(envelopes.begin(), envelopes.end(), comp);

        vector<int> heights;
        for (auto it : envelopes)
            heights.push_back(it[1]);

        int len = 1;
        vector<int> temp;
        temp.push_back(heights[0]);

        for (int i = 1; i < n; i++) {

            if (heights[i] > temp.back()) {
                len++;
                temp.push_back(heights[i]);
            } else {
                int ind = lower_bound(temp.begin(), temp.end(), heights[i]) -
                          temp.begin();
                temp[ind] = heights[i];
            }
        }
        return len;
    }
};