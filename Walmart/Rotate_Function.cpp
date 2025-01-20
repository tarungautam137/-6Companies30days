#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

        int n = nums.size(), i = 1, j = n - 1;

        vector<int> v = nums;
        for (int i = 0; i < n; i++)
            v.push_back(nums[i]);

        long long sum = 0, prod = 0, maxi = 0;

        for (int k = i; k <= j; k++) {

            sum += nums[k];
            prod += (k * nums[k]);
        }

        maxi = prod;
        while (j <= (2 * n - 2)) {

            j++;

            if (j <= (2 * n - 2)) {

                prod += ((n - 1) * v[j]);
                prod -= sum;

                sum += v[j];
                sum -= v[i];

                i++;
                maxi = max(maxi, prod);
            }
        }
        return maxi;
    }
};