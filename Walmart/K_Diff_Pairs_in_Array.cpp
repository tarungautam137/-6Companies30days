# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        int n = nums.size(), count = 0;

        map<int, int> m;

        for (int x : nums)
            m[x]++;

        for (auto it = m.begin(); it != m.end(); it++) {

            int num = (*it).first;

            if (k == 0) {
                if (m[num] > 1)
                    count++;
            } else if (m.find(num + k) != m.end())
                count++;
        }
        return count;
    }
};