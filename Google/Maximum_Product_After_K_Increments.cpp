# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ALWAYS INCREMENT MINIMUM ELEMENT.
    int maximumProduct(vector<int>& nums, int k) {

        int mod = 1e9 + 7;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int x : nums)
            pq.push(x);

        while (k > 0) {

            int x = pq.top();
            pq.pop();

            pq.push(x + 1);
            k--;
        }
        long long prod = 1;

        while (!pq.empty()) {

            int x = pq.top();
            pq.pop();

            prod = (prod * ((long long)x)) % mod;
        }
        return (int)(prod % 1000000007);
    }
};