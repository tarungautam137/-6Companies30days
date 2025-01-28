# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;

        for (int mask = 1; mask < (1 << 9); mask++) {

            int sum = 0, count = 0;
            vector<int> temp;

            for (int i = 0; i < 9; i++) {

                if ((1 << i) & mask) {

                    count++;
                    sum += (i + 1);
                    temp.push_back(i + 1);
                }
            }

            if (count == k && sum == n)
                ans.push_back(temp);
        }
        return ans;
    }
};