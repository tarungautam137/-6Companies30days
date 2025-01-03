# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {

        int n = nums.size(), count = 0;

        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {

                bool flag = true;

                for (int k = 1; k < i; k++) {
                    if (nums[k] <= nums[k - 1]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {

                    for (int k = j + 2; k < n; k++) {
                        if (nums[k] <= nums[k - 1]) {
                            flag = false;
                            break;
                        }
                    }
                    if (i >= 1 && j <= n - 2 && nums[j + 1] <= nums[i - 1])
                        flag = false;
                    if (flag)
                        count++;
                }
            }
        }
        return count;
    }
};