# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> index;
        index.push_back(-1);

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2)
                index.push_back(i);
        }
        index.push_back(n);

        if (index.size() < k)
            return 0;

        int i = 1, j = i + k - 1, count = 0;

        while (j < index.size() - 1) {

            int l = index[i] - index[i - 1];
            int r = index[j + 1] - index[j];

            count += (r * l);
            i++;
            j++;
        }
        return count;
    }
};