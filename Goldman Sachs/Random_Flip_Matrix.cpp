# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> mp;
    int count, rows, cols;

    Solution(int m, int n) {

        count = m * n;
        rows = m;
        cols = n;
    }

    vector<int> flip() {

        int ind = rand() % count;

        if (mp.find(ind) == mp.end()) mp[ind] = ind;

        int num = mp[ind];

        if (mp.find(count - 1) == mp.end()) mp[count - 1] = count - 1;
        mp[ind] = mp[count - 1];

        count--;

        vector<int> ans;
        ans.push_back(num / cols);
        ans.push_back(num % cols);

        return ans;
    }

    void reset() {

        mp.clear();
        count = rows * cols;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */